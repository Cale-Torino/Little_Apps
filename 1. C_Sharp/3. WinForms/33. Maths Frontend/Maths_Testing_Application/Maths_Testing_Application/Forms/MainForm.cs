using Newtonsoft.Json;
using SuperSimpleTcp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Maths_Testing_Application.SystemClass;
using static Maths_Testing_Application.TextClass;

namespace Maths_Testing_Application
{
    public partial class MainForm : Form
    {
        SimpleTcpClient client;
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            CreateFolder();
            LoadText();
            LoadTCP();
            TCPTimerStart();
            LoadTandC();
            string Msg = "MainForm_Load test";
            string json = "{\"MachineName\":\"" + Environment.MachineName +
            "\",\"Message\":\"" + Msg +
            "\",\"UserName\":\"" + Environment.UserName +
            "\",\"DateTime\":\"" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + "\"}";

            var Request = JsonConvert.DeserializeObject<RequestClass>(json);
            Invoke(new MethodInvoker(() => richTextBox.AppendText($"[{DateTime.Now}] : {Request.Message} => {Request.MachineName} {Environment.NewLine}")));
            tabControl1.TabPages.Remove(tabPage4);
            int _result = Logger.LoggerClass.Logger.WriteLine(" *** MainForm has loaded: [MainForm_Load] ***");
            richTextBox.AppendText($"[{DateTime.Now}] : Application Started" + Environment.NewLine);
        }

        private void LoadTandC()
        {
            try
            {
                TandCrichTextBox.Text = File.ReadAllText("TermsAndConditions.txt");
                Logger.LoggerClass.Logger.WriteLine(" *** LoadTandC Complete [MainForm] ***");
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message, "Load TCP Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                richTextBox.AppendText($"LoadTandC Error!{Environment.NewLine} {ex.Message} {Environment.NewLine}");
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }

        private void TCPTimerStart()
        {
            try
            {
                //Timer start
                TCPtimer.Start();
                ServerChecktimer.Start();
                Logger.LoggerClass.Logger.WriteLine(" *** TCP Timer Start [MainForm] ***");
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message, "Load TCP Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                richTextBox.AppendText($"TCP Timer Start Error!{Environment.NewLine} {ex.Message} {Environment.NewLine}");
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }

        private void LoadTCP()
        {
            try
            {
                //Check if your machine is listening on port '4953' that you specified by running the command netstat -an
                //within command prompt.
                //If it is not listening on that port,
                //either change the port you are sending the packet to to a port that is listening or open the port for listening.
                // instantiate
                //client = new SimpleTcpClient("127.0.0.1:4953");//0.0.0.0:4953
                client = new SimpleTcpClient("127.0.0.1:4953", true, "simpletcp.pfx", "simpletcp");//0.0.0.0:4953
                // set events
                client.Events.Connected += Connected;
                client.Events.Disconnected += Disconnected;
                client.Events.DataReceived += DataReceived;

                //Authenticate
                client.Settings.MutuallyAuthenticate = true;
                client.Settings.AcceptInvalidCertificates = true;

                //Add loger
                client.Logger = TCPLogger;

                // let's go!
                client.Connect();

                // once connected to the server...
                string jSon = JSONCommsClass.JSONSending.JSONFormat("Hello Server");
                string encrypt = EncryptionLib.EncryptionClass.EncryptString(EncryptionLib.EncryptionClass.ToSecureString($"{jSon}"));
                client.Send(encrypt);
                Logger.LoggerClass.Logger.WriteLine(" *** Load TCP [MainForm] ***");
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message, "Load TCP Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                richTextBox.AppendText($"Load TCP Error!{Environment.NewLine} {ex.Message} {Environment.NewLine}");
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }

        private void TCPLogger(string msg)
        {
            Invoke((MethodInvoker)delegate ()
            {
                richTextBox.AppendText($"{DateTime.Now} : TCP LOG :{msg} | {Environment.NewLine}");
            });
        }

        private void Connected(object sender, ConnectionEventArgs e)
        {     
            Invoke((MethodInvoker)delegate ()
            {
                richTextBox.AppendText($"[{DateTime.Now}] : ***Server { e.IpPort} connected" + Environment.NewLine);
            });
        }

        private void Disconnected(object sender, ConnectionEventArgs e)
        {       
            Invoke((MethodInvoker)delegate ()
            {
                richTextBox.AppendText($"[{DateTime.Now}] : ***Server { e.IpPort} disconnected" + Environment.NewLine);
            });
        }

        private void DataReceived(object sender, DataReceivedEventArgs e)
        {
            Invoke((MethodInvoker)delegate ()
            {
                string decrypt = EncryptionLib.EncryptionClass.ToInsecureString(EncryptionLib.EncryptionClass.DecryptString(Encoding.UTF8.GetString(e.Data)));
                richTextBox.AppendText($"[{DateTime.Now}] : [{e.IpPort}] {decrypt}" + Environment.NewLine);
                var Request = JsonConvert.DeserializeObject<RequestClass>(decrypt);
                if (Request.Message == "Maths")
                {
                    label1.Text = "Maths";
                } 
                else if (Request.Message == "Wiskunde") 
                {
                    label1.Text = "Wiskunde";
                }
            });

        }

        private void LoadText()
        {
            try
            {
                EngLan.HomeText(label1);
                EngLan.Paragraph1(label2);
                EngLan.Paragraph2(label3);
                EngLan.Paragraph3(label4);
                EngLan.Paragraph4(label5);
                Logger.LoggerClass.Logger.WriteLine(" *** Load Text [MainForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Load Text Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
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

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open the about form
            Form f = new AboutForm();
            f.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox.AppendText(DeviceSpecs.OSsys() + Environment.NewLine);
            richTextBox.AppendText(DeviceSpecs.GetAll() + Environment.NewLine);
        }

        private void Nextbutton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
            {
                string jSon = JSONCommsClass.JSONSending.JSONFormat("Hello, world infinate!");
                string encrypt = EncryptionLib.EncryptionClass.EncryptString(EncryptionLib.EncryptionClass.ToSecureString(jSon));
                client.Send(encrypt);
            }
            
            tabControl1.SelectTab(1);
        }

        private void StartTestbutton_Click(object sender, EventArgs e)
        {
            tabControl1.SelectTab(2);  // 0-based index, this shows the second tab
        }

        private void Nextquestionbutton1_Click(object sender, EventArgs e)
        {
            tabControl1.TabPages.Remove(tabPage3);
            tabControl1.TabPages.Add(tabPage4);
            tabControl1.SelectTab(tabPage4);
        }

        private void Nextquestionbutton2_Click(object sender, EventArgs e)
        {

        }

        private void Backbutton2_Click(object sender, EventArgs e)
        {
            tabControl1.TabPages.Remove(tabPage4);
            tabControl1.TabPages.Add(tabPage3);
            tabControl1.SelectTab(tabPage3);
        }

        private void TCPtimer_Tick(object sender, EventArgs e)
        {
            long Received = client.Statistics.ReceivedBytes;
            long Sent = client.Statistics.SentBytes;
            TimeSpan UpTime = client.Statistics.UpTime;
            DateTime StartTime = client.Statistics.StartTime;
            toolStripStatusLabel.Text = $" StartTime:{StartTime} UpTime:{UpTime} Received:{Received} Sent:{Sent}";
        }

        private void ServerChecktimer_Tick(object sender, EventArgs e)
        {
            if (!client.IsConnected)
            {
                Invoke((MethodInvoker)delegate ()
                {
                    client.Dispose();
                    LoadTCP();
                });
            }
        }
    }
}
