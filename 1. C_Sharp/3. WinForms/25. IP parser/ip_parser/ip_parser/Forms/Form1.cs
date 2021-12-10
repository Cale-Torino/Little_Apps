using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static ip_parser.LoggerClass;

namespace ip_parser
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Get_IP()
        {
            try
            {
                //var httpClient = new HttpClient();
                //string ip = await httpClient.GetStringAsync("https://api.myip.com");
                //string ip = await httpClient.GetStringAsync("https://api.ipify.org");
                //MessageBox.Show(ip);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }
        private void CreateFolder()
        {
            try
            {
                //CreatFolder
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + "\\Logs");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //https://ipapi.com/
            //https://ipfind.com/
            //https://ip-api.com/docs/api:batch#test
            //https://ipwhois.io/documentation
            // IPFIND = 63b2baec-2873-422b-9108-dcc441991275
            CreateFolder();
            Get_IP();
            Logger.WriteLine(" ***- APPLICATION STARTED -*** ");
            richTextBox1.Text = "8.8.8.8";
            richTextBox2.Text = "8.8.8.8;146.235.190.57;15.241.21.171;52.216.88.244;185.169.133.187;146.235.190.53;102.249.0.59;15.241.21.120;15.241.21.119";

            toolStripStatusLabel1.Text = "Ready";
        }
        private void initListView()
        {
            // Add columns
            listView1.Columns.Add("IP", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Type", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Continent", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Continent Code", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Country", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Country Code", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Region", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("City", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Latitude", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Longitude", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("ISP", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Timezone", -2, HorizontalAlignment.Left);
            listView1.Columns.Add("Timezone Name", -2, HorizontalAlignment.Left);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (listView1.Columns.Count == 0)
                {
                    initListView();
                }
                //one ip at a time :(
                using (var webClient = new System.Net.WebClient())
                {
                    string ip = richTextBox1.Text;
                    string URL = "http://free.ipwhois.io/json/" + ip;
                    var json = webClient.DownloadString(URL);
                    // Now parse with JSON.Net
                    JObject response = JObject.Parse(json);
                    string _ip = (string)response["ip"];
                    string _type = (string)response["type"];
                    string _continent = (string)response["continent"];
                    string _continent_code = (string)response["continent_code"];
                    string _country = (string)response["country"];
                    string _country_code = (string)response["country_code"];
                    string _region = (string)response["region"];
                    string _city = (string)response["city"];
                    string _latitude = (string)response["latitude"];
                    string _longitude = (string)response["longitude"];
                    string _isp = (string)response["isp"];
                    string _timezone = (string)response["timezone"];
                    string _timezone_name = (string)response["timezone_name"];
                    //MessageBox.Show(_ip + _type+ _continent+ _continent_code+ _country+ _country_code+ _region+ _city+ _latitude+ _longitude+ _isp+ _timezone+ _timezone_name);
                    listView1.SmallImageList = imageList1;
                    ListViewItem lst = new ListViewItem(new[] { _ip, _type, _continent, _continent_code, _country, _country_code, _region, _city, _latitude, _longitude, _isp, _timezone, _timezone_name });
                    //lst.Text = "-Flag";
                    switch (_country_code)
                    {
                        case "US":
                            lst.ImageIndex = 0;
                            break;
                        case "ZA":
                            lst.ImageIndex = 1;
                            break;
                        case "NL":
                            lst.ImageIndex = 2;
                            break;
                        default:
                            lst.ImageIndex = 3;
                            break;
                    }
                    listView1.Items.Add(lst);
                    listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
                    listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
                    richTextBox3.AppendText("[" + DateTime.Now.ToString() + "] : " + ip + Environment.NewLine);
                    Logger.WriteLine(" ***Single Send***");
                    Logger.WriteLine(" ***Address: " + ip);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void Bulk_Process(string ip)
        {
            try
            {
                if (listView1.Columns.Count == 0)
                {
                    initListView();
                }
                //one ip at a time :(
                using (var webClient = new System.Net.WebClient())
                {
                    string URL = "http://free.ipwhois.io/json/" + ip;
                    var json = webClient.DownloadString(URL);
                    // Now parse with JSON.Net
                    JObject response = JObject.Parse(json);
                    string _ip = (string)response["ip"];
                    string _type = (string)response["type"];
                    string _continent = (string)response["continent"];
                    string _continent_code = (string)response["continent_code"];
                    string _country = (string)response["country"];
                    string _country_code = (string)response["country_code"];
                    string _region = (string)response["region"];
                    string _city = (string)response["city"];
                    string _latitude = (string)response["latitude"];
                    string _longitude = (string)response["longitude"];
                    string _isp = (string)response["isp"];
                    string _timezone = (string)response["timezone"];
                    string _timezone_name = (string)response["timezone_name"];
                    //MessageBox.Show(_ip + _type+ _continent+ _continent_code+ _country+ _country_code+ _region+ _city+ _latitude+ _longitude+ _isp+ _timezone+ _timezone_name);
                    listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
                    listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
                    listView1.SmallImageList = imageList1;
                    ListViewItem lst = new ListViewItem(new[] { _ip, _type, _continent, _continent_code, _country, _country_code, _region, _city, _latitude, _longitude, _isp, _timezone, _timezone_name });
                    //lst.Text = "-Flag";
                    switch (_country_code)
                    {
                        case "US":
                            lst.ImageIndex = 0;
                            break;
                        case "ZA":
                            lst.ImageIndex = 1;
                            break;
                        case "NL":
                            lst.ImageIndex = 2;
                            break;
                        default:
                            lst.ImageIndex = 3;
                            break;
                    }
                    listView1.Items.Add(lst);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void Bulk_send()
        {
            // String of authors  
            //string authors = "Mahesh Chand;Henry He;Chris Love;Raj Beniwal;Praveen Kumar";
            string _ip = richTextBox2.Text;
            // Split authors separated by a comma followed by space  
            string[] authorsList = _ip.Split(';');
            Logger.WriteLine(" ***Bulk Send*** ");
            foreach (var ip in authorsList)
            {
                Bulk_Process(ip);              
                Logger.WriteLine(" ***Address: " + ip);
                richTextBox3.AppendText("[" + DateTime.Now.ToString() + "] : " + ip + Environment.NewLine);
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Bulk_send();
        }

        private void clearListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //exit YES/NO
            Logger.WriteLine(" ***Clear Button Clicked*** ");
            string _text = "Do you really want to clear the list?";
            string _caption = "Clear List?";
            var selectedOption = MessageBox.Show(_text, _caption, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (selectedOption == DialogResult.Yes)
            {
                try
                {
                    listView1.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "Exit Error", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    return;
                }

            }
            else if (selectedOption == DialogResult.No)
            {
                //Do nothing
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //about
            Logger.WriteLine(" ***About Box Clicked*** ");
            Form f2 = new Form2();
            f2.ShowDialog();
        }

        private void clearMemoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //exit YES/NO
            Logger.WriteLine(" ***Clear Memo Button Clicked*** ");
            string _text = "Do you really want to clear the Memo?";
            string _caption = "Clear Memo?";
            var selectedOption = MessageBox.Show(_text, _caption, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (selectedOption == DialogResult.Yes)
            {
                try
                {
                    richTextBox3.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "Exit Error", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    return;
                }

            }
            else if (selectedOption == DialogResult.No)
            {
                //Do nothing
            }
        }
        private void Reallyexit()
        {
            //exit YES/NO
            string _text = "Do you really want to exit the application?";
            string _caption = "Exit Application?";
            var selectedOption = MessageBox.Show(_text, _caption, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (selectedOption == DialogResult.Yes)
            {
                try
                {
                    Environment.Exit(1);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "Exit Error", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    return;
                }

            }
            else if (selectedOption == DialogResult.No)
            {
                //Do nothing
            }
        }
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //exit
            Logger.WriteLine(" ***Exit Clicked*** ");
            Reallyexit();
        }
    }
}
