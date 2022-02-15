using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Maths_Testing_Application
{
    internal class SystemClass
    {
        public class DeviceSpecs
        {
            public static string GetAll()
            {
                PerformanceCounter cpuCounter;
                PerformanceCounter ramCounter;

                cpuCounter = new PerformanceCounter("Processor", "% Processor Time", "_Total");
                ramCounter = new PerformanceCounter("Memory", "Available MBytes");

                string cpu = cpuCounter.NextValue()+" %";
                string ram = ramCounter.NextValue()+" MB";
                return $"CPU:{cpu}, Ram:{ram}, Username:{Environment.UserName}";
            }
            public static async void Get_IP()
            {
                try
                {
                    var httpClient = new HttpClient();
                    string ip = await httpClient.GetStringAsync("http://free.ipwhois.io/json/");
                    //JObject response = JObject.Parse(ip);
                    //string _sig = (string)response["signature"];
                    //new WebClient().DownloadString("http://ip.domain.com/device_manager/api/get/setNetworkData.php?Networkdata=" + ip);
                    Logger.LoggerClass.Logger.WriteLine(" *** Current Network: " + ip);
                }
                catch (Exception ex)
                {
                    //MessageBox.Show(ex.Message);
                    Logger.LoggerClass.Logger.WriteLine(" *** Current Network: " + ex);
                    return;
                }
            }
            [DllImport("kernel32.dll")]
            [return: MarshalAs(UnmanagedType.Bool)]
            static extern bool GetPhysicallyInstalledSystemMemory(out long TotalMemoryInKilobytes);
            public static string OSsys()
            {
                bool IOS = Environment.Is64BitOperatingSystem;
                string OSb;
                if (IOS == true)
                {
                    OSb = "64-Bit-OperatingSystem";
                }
                else
                {
                    OSb = "32-Bit-OperatingSystem";
                }
                int PC = Environment.ProcessorCount;
                int CORES = PC / 2;
                long memKb;
                GetPhysicallyInstalledSystemMemory(out memKb);
                long RAM = memKb / 1024 / 1024;
                string RAMM = RAM.ToString() + " GB";
                string _S = "USERNAME=" + Environment.UserName + "&MACHINENAME=" + Environment.MachineName + "&OSVERSION=" + Environment.OSVersion +
                    "&OS=" + OSb + "&VERSION=" + Environment.Version + "&TICKCOUNT=" + Environment.TickCount + "&CPUCOUNT=" + PC + "&CORES=" +
                    CORES + "&RAM=" + RAMM + "&SYSDIRECTORY=" + Environment.SystemDirectory + "&WORKINGSET=" + Environment.WorkingSet;
                return _S;
            }
        }

    }
}
