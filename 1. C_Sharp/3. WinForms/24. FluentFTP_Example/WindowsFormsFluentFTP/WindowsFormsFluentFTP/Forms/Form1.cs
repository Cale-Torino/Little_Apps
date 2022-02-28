using FluentFTP;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsFluentFTP
{
    public partial class Form1 : Form
    {
        FtpClient client;
        public Form1()
        {
            InitializeComponent();
        }

        private async void Connect() 
        {
            // create an FTP client
            client = new FtpClient(textBox1.Text, Convert.ToInt32(numericUpDown1.Value), textBox2.Text, textBox3.Text);
            toolStripProgressBar1.Value = 10;
            // begin connecting to the server
            await client.ConnectAsync();
            toolStripStatusLabel1.Text = "Downloading List...";
            toolStripProgressBar1.Value = 50;
            // get a list of files and directories in the "/htdocs" folder
            foreach (FtpListItem item in await client.GetListingAsync("/LOG_FILE"))
            {

                // if this is a file
                if (item.Type == FtpFileSystemObjectType.File)
                {

                    // get the file size
                    long size = await client.GetFileSizeAsync(item.FullName);

                    // calculate a hash for the file on the server side (default algorithm)
                    FtpHash hash = await client.GetChecksumAsync(item.FullName);
                    textBox4.AppendText(item.ToString()+size);
                }

                if (item.Type == FtpFileSystemObjectType.Directory)
                {
                    textBox4.AppendText(item.FullName);
                }

                // get modified date/time of the file or folder
                DateTime time = await client.GetModifiedTimeAsync(item.FullName);
                textBox4.AppendText("_" + time + Environment.NewLine);
            }
            groupBox1.Enabled = true;
            toolStripStatusLabel1.Text = "Completed Time: "+DateTime.Now;
            toolStripProgressBar1.Value = 100;
            MessageBox.Show("Retrived", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private async void DisConnect()
        {
            try
            {
                // disconnect! good bye!
                await client.DisconnectAsync();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "0.0.0.0";
            textBox2.Text = "user";
            textBox3.Text = "pword";
            toolStripStatusLabel1.Text = "Ready";

        }

        private void testeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                toolStripProgressBar1.Value = 0;
                toolStripStatusLabel1.Text = "Connecting...";
                groupBox1.Enabled = false;
                Connect();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }
        }

        private void test2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                toolStripStatusLabel1.Text = "Disconnected";
                DisConnect();               
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }
            MessageBox.Show("Disconnected", "Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox4.Clear();
        }

        private void copyAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox4.SelectAll();
            textBox4.Copy();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form f2 = new Form2();
            f2.ShowDialog();
        }
    }
}
