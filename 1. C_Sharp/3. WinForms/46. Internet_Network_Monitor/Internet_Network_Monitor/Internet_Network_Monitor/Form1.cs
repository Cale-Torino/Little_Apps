using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Internet_Network_Monitor
{
    public partial class Form1 : Form
    {
        struct IO_COUNTERS
        {
            public ulong ReadOperationCount;
            public ulong WriteOperationCount;
            public ulong OtherOperationCount;
            public ulong ReadTransferCount;
            public ulong WriteTransferCount;
            public ulong OtherTransferCount;
        }

        [DllImport(@"kernel32.dll", SetLastError = true)]
        static extern bool GetProcessIoCounters(IntPtr hProcess, out IO_COUNTERS counters);

        private string networkCardName = string.Empty;
        private bool isSteamUsingDisk = false;
        private bool monitoringStatus = false;
        private bool messageShown = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                Thread cardThread = new Thread(() => LoadNetworkCardName());
                Thread diskThread = new Thread(() => MonitorSteamDiskUsage());
                Thread monitorThread = new Thread(() => MonitorAutoShutdown());

                cardThread.Start();
                diskThread.Start();
                monitorThread.Start();
            }
            catch (Exception ex)
            {
                //Util.LogToFile(ex.ToString());
            }
        }
        private void MonitorAutoShutdown()
        {
            int idleCounter = 0;
            int idleTresholdCounter = 0;

            while (true)
            {
                try
                {
                    int shutdownAfterSeconds = 10;
                    int speedTreshold = 20 * 1000;
                    int idleTreshold = 3;

                    if (!string.IsNullOrEmpty(networkCardName))
                    {
                        double bytesUsage = GetNetworkUtilization(networkCardName);

                        networkSpeedLabel.Invoke((MethodInvoker)delegate
                        {
                            networkSpeedLabel.Text = (((bytesUsage / 1024f) / 1024f).ToString("####0.00") + " MB/s").Replace(",", ".");

                            if (diskDetectionCheckbox.Checked)
                            {
                                diskActivityLabel.Text = "Steam Using Disk: " + (isSteamUsingDisk ? "Yes" : "No");
                            }
                            else
                            {
                                diskActivityLabel.Text = "Steam Using Disk: Disabled";
                            }
                        });

                        if (monitoringStatus)
                        {
                            if (bytesUsage < speedTreshold)
                            {
                                if (!diskDetectionCheckbox.Checked)
                                {
                                    idleCounter++;
                                }
                                else if (diskDetectionCheckbox.Checked && !isSteamUsingDisk)
                                {
                                    idleCounter++;
                                }

                                idleTresholdCounter = 0;
                            }
                            else
                            {
                                idleTresholdCounter++;

                                if (idleTresholdCounter > idleTreshold)
                                {
                                    idleCounter = 0;
                                }
                            }

                            if (idleCounter > shutdownAfterSeconds)
                            {
                                idleCounter = 0;
                                Shutdown();
                                ToggleStatus();
                            }

                            if (idleCounter == 0)
                            {
                                statusLabel.Invoke((MethodInvoker)delegate
                                {
                                    statusLabel.Text = "Downloading...";
                                });
                            }
                            else
                            {
                                statusLabel.Invoke((MethodInvoker)delegate
                                {
                                    statusLabel.Text = String.Format("Shutting down in {0} seconds", shutdownAfterSeconds - idleCounter);
                                });
                            }
                        }
                        else
                        {
                            idleCounter = 0;
                            idleTresholdCounter = 0;

                            statusLabel.Invoke((MethodInvoker)delegate
                            {
                                statusLabel.Text = "";
                            });
                        }
                    }
                }
                catch (Exception ex)
                {
                    //Util.LogToFile(ex.ToString());
                }
                finally
                {
                    Thread.Sleep(1000);
                }
            }
        }

        private void ToggleStatus()
        {
            monitoringStatus = !monitoringStatus;

            toggleStatusLabel.Invoke((MethodInvoker)delegate
            {
                toggleStatusLabel.Text = monitoringStatus ? "ON" : "OFF";
            });
        }

        private void MonitorSteamDiskUsage()
        {
            ulong lastValue = 0;
            bool run = true;
            while (run)
            {
                try
                {
                    using (Process p = Process.GetProcessesByName("steam").FirstOrDefault())
                    {
                        if (p == null)
                        {
                            MessageBox.Show("Steam not running");
                            run = false;
                            //break;
                            throw new InvalidOperationException("Steam not running");
                        }
                        else
                        {
                            if (GetProcessIoCounters(p.Handle, out IO_COUNTERS counters))
                            {
                                if (lastValue != 0 && counters.WriteTransferCount != lastValue && counters.WriteTransferCount - lastValue > 100000)
                                {
                                    isSteamUsingDisk = true;
                                }
                                else
                                {
                                    isSteamUsingDisk = false;
                                }

                                lastValue = counters.WriteTransferCount;
                            }

                            Thread.Sleep(2000);
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                    //Util.LogToFile(ex.ToString());
                }
            }
        }
        private static void Shutdown()
        {
            try
            {
                Process.Start("shutdown", "/s /t 15");

                DialogResult result = MessageBox.Show("Your computer is shutting down in 15 seconds! Do you want to CANCEL the shutdown? Press YES to ABORT THE SHUTDOWN. Press NO to SHUTDOWN IMEDIATELY.", "Confirm", MessageBoxButtons.YesNo);

                if (result == DialogResult.Yes)
                {
                    Process.Start("shutdown", "/a");
                }
                else
                {
                    Process.Start("shutdown", "/s");
                }
            }
            catch { }
        }

        private double GetNetworkUtilization(string networkCard)
        {
            try
            {
                PerformanceCounter dataReceivedCounter = new PerformanceCounter("Network Interface", "Bytes Received/sec", networkCard);

                float receiveSum = 0;

                for (int index = 0; index < 50; index++)
                {
                    receiveSum += dataReceivedCounter.NextValue();
                }

                float dataReceived = receiveSum / 50;

                return dataReceived;
            }
            catch (Exception ex)
            {
                //Util.LogToFile(ex.ToString());
            }

            return 0;
        }

        private void LoadNetworkCardName()
        {
            try
            {
                PerformanceCounterCategory category = new PerformanceCounterCategory("Network Interface");
                string[] instancename = category.GetInstanceNames();

                while (string.IsNullOrEmpty(networkCardName))
                {
                    foreach (string name in instancename)
                    {
                        double utilization = GetNetworkUtilization(name.TrimStart().TrimEnd());

                        if (utilization != 0)
                        {
                            networkCardName = name;

                            networkCardLabel.Invoke((MethodInvoker)delegate
                            {
                                networkCardLabel.Text = networkCardName;
                            });

                            break;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                //Util.LogToFile(ex.ToString());
            }
        }

        private void togglebutton_Click(object sender, EventArgs e)
        {
            ToggleStatus();
        }
    }
}
