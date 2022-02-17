using SimpleTcp;
using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

//https://github.com/jchristn/simpletcp

namespace Maths_Testing_Application_TCP_Server
{
    public partial class MainForm : Form
    {
        SimpleTcpServer server;
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            CreateFolder();
            SetupTCP();
            TCPTimerStart();
            Logger.LoggerClass.Logger.WriteLine(" *** Main Form Load Complete [MainForm] ***");
        }

        private void CreateFolder()
        {
            try
            {
                //Create the folders used by the app
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + @"\Logs");
                Logger.LoggerClass.Logger.WriteLine(" *** Application Start [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Application Start" + Environment.NewLine);
                Logger.LoggerClass.Logger.WriteLine(" *** CreateDirectory Success [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Logs Create Directory Success" + Environment.NewLine);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Error:" + ex.Message + Environment.NewLine);
                return;
            }
        }

        private void SetupTCP()
        {
            try
            {
                IPtextBox.Text = "0.0.0.0:4953";//4953 6608
                Sendbutton.Enabled = false;
                Disconnectbutton.Enabled = false;

                //server = new SimpleTcpServer(IPtextBox.Text);
                server = new SimpleTcpServer(IPtextBox.Text, true, "simpletcp.pfx", "simpletcp");
                server.Keepalive.EnableTcpKeepAlives = true;
                server.Keepalive.TcpKeepAliveInterval = 30;      // seconds to wait before sending subsequent keepalive
                server.Keepalive.TcpKeepAliveTime = 30;          // seconds to wait before sending a keepalive
                server.Keepalive.TcpKeepAliveRetryCount = 5;    // number of failed keepalive probes before terminating connection

                //Authenticate
                //server.Settings.MutuallyAuthenticate = true;

                //Add loger
                server.Logger = TCPLogger;

                server.Events.ClientConnected += Events_ClientConnected;
                server.Events.ClientDisconnected += Events_ClientDisconnected;
                server.Events.DataReceived += Events_DataReceived;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Load Logger Class DLL Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }

        private void TCPLogger(string msg)
        {
            LogstextBox.AppendText($"{DateTime.Now} : TCP LOG :{msg} | {Environment.NewLine}");
        }

        private void Events_DataReceived(object sender, DataReceivedEventArgs e)
        {
            Invoke((MethodInvoker)delegate ()
            {
                //LogstextBox.AppendText($"{DateTime.Now} : {e.IpPort} | {Encoding.UTF8.GetString(e.Data)}{Environment.NewLine}");
                //string[] data = Encoding.UTF8.GetString(e.Data).Split(',');
                //string ID = data[1];
                string ID = Encoding.UTF8.GetString(e.Data);
                string decrypt = EncryptionLib.EncryptionClass.ToInsecureString(EncryptionLib.EncryptionClass.DecryptString(ID));               
                LogstextBox.AppendText($"{DateTime.Now} : {e.IpPort} | {decrypt}{Environment.NewLine}");
            });
            
        }

        private void Events_ClientDisconnected(object sender, ClientDisconnectedEventArgs e)
        {
            Invoke((MethodInvoker)delegate ()
            {
                LogstextBox.Text += $"{DateTime.Now} : {e.IpPort} | Disconnected : {e.Reason}{Environment.NewLine}";
                listBox.Items.Remove(e.IpPort);
            });

        }

        private void Events_ClientConnected(object sender, ClientConnectedEventArgs e)
        {
            Invoke((MethodInvoker)delegate ()
            {
                LogstextBox.Text += $"{DateTime.Now} : {e.IpPort} | Connected {Environment.NewLine}";
                listBox.Items.Add(e.IpPort);
                //server.Send(e.IpPort, "Pinging...");
            });
        }

        private void Sendbutton_Click(object sender, EventArgs e)
        {
            if (server.IsListening)
            {
                if (!string.IsNullOrEmpty(MSGcomboBox.Text) && listBox.SelectedItem != null)
                {
                    string encrypt = EncryptionLib.EncryptionClass.EncryptString(EncryptionLib.EncryptionClass.ToSecureString(MSGcomboBox.Text));
                    server.Send(listBox.SelectedItem.ToString(), encrypt);
                    LogstextBox.Text += $"{DateTime.Now} : Server sent = {MSGcomboBox.Text}{Environment.NewLine}";
                    //MSGtextBox.Text = string.Empty;
                }
            }
        }

        private void Connectbutton_Click(object sender, EventArgs e)
        {
            if (!server.IsListening)
            {
                Connectbutton.Enabled = false;
                Disconnectbutton.Enabled = true;
                server.Start();
                LogstextBox.Text += $"{DateTime.Now} : Listening... {Environment.NewLine}";
                Connectbutton.Enabled = false;
                Sendbutton.Enabled = true;
            }
        }

        private void Disconnectbutton_Click(object sender, EventArgs e)
        {
            if (server.IsListening)
            {
                Disconnectbutton.Enabled = false;
                Connectbutton.Enabled = true;
                Sendbutton.Enabled = false;
                LogstextBox.Text += $"{DateTime.Now} : Listening disconnected {Environment.NewLine}";
                foreach (var listBoxItem in listBox.Items)
                {
                    // use the currently iterated list box item
                    server.DisconnectClient(listBoxItem.ToString());
                }
                server.Stop();
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open the about form
            Form f = new AboutForm();
            f.ShowDialog();
        }

        private void settingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open the settings form
            Form f = new SettingsForm();
            f.ShowDialog();
        }

        private void TCPTimerStart()
        {
            try
            {
                //Timer start
                TCPtimer.Enabled = true;
                TCPtimer.Start();
                Logger.LoggerClass.Logger.WriteLine(" *** TCP Timer Start [MainForm] ***");
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message, "Load TCP Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                LogstextBox.AppendText($"TCP Timer Start Error!{Environment.NewLine} {ex.Message} {Environment.NewLine}");
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }

        private void TCPtimer_Tick(object sender, EventArgs e)
        {
            long Received = server.Statistics.ReceivedBytes;
            long Sent = server.Statistics.SentBytes;
            TimeSpan UpTime = server.Statistics.UpTime;
            DateTime StartTime = server.Statistics.StartTime;
            LogstextBox.AppendText($" {DateTime.Now} | StartTime:{StartTime} UpTime:{UpTime} Received:{Received} Sent:{Sent} {Environment.NewLine}");
        }
    }
}
