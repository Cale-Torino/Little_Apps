using Newtonsoft.Json;
using SimpleHttp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

//https://stackify.com/log4net-guide-dotnet-logging/

//http://127.0.0.1:1337/log

//pfxPath- password- port-
//https://coderead.wordpress.com/2014/08/07/enabling-ssl-for-self-hosted-nancy/

namespace HTTPSERVER
{
    public partial class MainForm : Form
    {
        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public string protocol = "";
        public bool useHttps;
        public MainForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            log.Info("**APPLICATION START**");
            IPBox.Text = "127.0.0.1";
            PortUpDown.Value = 1337;//1337
            HTTPButton.Checked = true;
            HTTPSButton.Checked = false;
            //log.Debug("Hello Debug world!");
            //log.Error("Hello Error world!");
            //log.Fatal("Hello Fatal world!");
            //log.Warn("Hello Warn world!");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (backgroundWorker1.IsBusy)
            {
                MessageBox.Show("backgroundWorker1 IsBusy", "Exception", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else 
            {
                if (HTTPButton.Checked)
                {
                   protocol = "http";
                   useHttps = false;
                }
                else if (HTTPSButton.Checked)
                {
                   protocol = "https";
                   useHttps = true;
                }
                backgroundWorker1.RunWorkerAsync();
            }

        }
        public static string LocalIPAddress()
        {
            var host = Dns.GetHostEntry(Dns.GetHostName());

            foreach (var ip in host.AddressList)
            {
                if (ip.AddressFamily == AddressFamily.InterNetwork)
                {
                    return ip.ToString();
                }
            }

            throw new Exception("No network adapters with an IPv4 address in the system!");
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            try
            {
                Route.Before = (rq, rp) => 
                { 
                    Invoke(new MethodInvoker(() => richTextBox1.AppendText($"Requested: {rq.Url.PathAndQuery}"+Environment.NewLine)));
                    log.Info($"**HTTP REQUEST | Requested: {rq.Url.PathAndQuery}");
                    return false;
                };
                
                Route.Add("/log", (req, res, props) =>
                {
                    res.AsText("GET SUCCSESS");
                }, "GET");

                Route.Add("/logs", (req, res, props) =>
                {
                    using (var reader = new StreamReader(req.InputStream, Encoding.UTF8, true, 1024, false))
                    {
                        try
                        {
                            var json = reader.ReadToEnd();
                            var Request = JsonConvert.DeserializeObject<RequestClass>(json);
                            Invoke(new MethodInvoker(() => richTextBox1.AppendText($"{Request.Tag} {Environment.NewLine}")));
                            log.Info($"**HTTP DATA | Request: {json}");
                        }
                        catch (Exception ex)
                        {
                            //MessageBox.Show(ex.Message, "Reader", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            Invoke(new MethodInvoker(() => richTextBox1.AppendText($"Error: {ex.Message} {Environment.NewLine}")));
                            log.Error(" *** Error:" + ex.Message + " [MainForm] ***");
                            return;
                        }
                    }

                    res.AsText($"POST SUCCSESS");
                }, "POST");

                Invoke(new MethodInvoker(() => richTextBox1.AppendText($"[Server Running] | port: {int.Parse(PortUpDown.Text)} | IP: {LocalIPAddress()}" + Environment.NewLine)));
                HttpServer.ListenAsync(int.Parse(PortUpDown.Text), CancellationToken.None, Route.OnHttpRequestAsync, useHttps: useHttps).Wait();
                //var cts = new CancellationTokenSource();
                //var ts = HttpServer.ListenAsync(Port, cts.Token, Route.OnHttpRequestAsync, useHttps: true, 32);
                //AppExit.WaitFor(cts, ts);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Exception", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            using (HttpClient client = new HttpClient())
            {
                //client.DefaultRequestHeaders.Add("Authorization", "Bearer token");
                RequestClass Request = new RequestClass
                {
                    Tag = "Hello",
                    Email = "james@example.com",
                    Active = true,
                    CreatedDate = new DateTime(2021, 1, 20, 0, 0, 0, DateTimeKind.Utc),
                    Roles = new List<string>
                    {
                        "User",
                        "Admin"
                    }
                };
                string json = JsonConvert.SerializeObject(Request);
                StringContent httpContent = new StringContent(json, Encoding.UTF8, "application/json");
                try
                {
                    using (HttpResponseMessage response = await client.PostAsync($"{protocol}://{IPBox.Text}:{int.Parse(PortUpDown.Text)}/logs", httpContent))
                    {
                        using (HttpContent content = response.Content)
                        {
                            //Read the result and display in Textbox
                            string result = await content.ReadAsStringAsync();//Result string JSON
                            string reasonPhrase = response.ReasonPhrase;//Reason OK, FAIL etc.
                            Invoke(new MethodInvoker(() => richTextBox1.AppendText(result + Environment.NewLine)));
                            Invoke(new MethodInvoker(() => richTextBox1.AppendText(reasonPhrase + Environment.NewLine)));
                            log.Info($"**HTTP TEST RESULT | result: {result} reasonPhrase: {reasonPhrase}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "Could not test link", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    log.Error(" *** Error:" + ex.Message + " [MainForm] ***");
                    return;
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }
    }
}
