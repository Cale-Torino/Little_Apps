using SimpleTcp;
using System;
using System.Text;
using System.Windows.Forms;

//https://github.com/jchristn/simpletcp

namespace SuperSimpleTCP
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
            IPtextBox.Text = "0.0.0.0:4953";//4953 6608
            Sendbutton.Enabled = false;
            Disconnectbutton.Enabled = false;

            server = new SimpleTcpServer(IPtextBox.Text);
            server.Keepalive.EnableTcpKeepAlives = true;
            server.Keepalive.TcpKeepAliveInterval = 30;      // seconds to wait before sending subsequent keepalive
            server.Keepalive.TcpKeepAliveTime = 30;          // seconds to wait before sending a keepalive
            server.Keepalive.TcpKeepAliveRetryCount = 5;    // number of failed keepalive probes before terminating connection

            server.Events.ClientConnected += Events_ClientConnected;
            server.Events.ClientDisconnected += Events_ClientDisconnected;
            server.Events.DataReceived += Events_DataReceived;
        }

        private void Events_DataReceived(object sender, DataReceivedEventArgs e)
        {
            Invoke((MethodInvoker)delegate ()
            {
                //LogstextBox.AppendText($"{DateTime.Now} : {e.IpPort} | {Encoding.UTF8.GetString(e.Data)}{Environment.NewLine}");
                string[] data = Encoding.UTF8.GetString(e.Data).Split(',');
                string ID = data[1];
                LogstextBox.AppendText($"{DateTime.Now} : {e.IpPort} | {ID}{Environment.NewLine}");
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
                    server.Send(listBox.SelectedItem.ToString(), MSGcomboBox.Text);
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
    }
}
