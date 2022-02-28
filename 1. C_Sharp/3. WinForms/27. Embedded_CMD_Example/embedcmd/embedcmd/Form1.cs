using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace embedcmd
{
    public partial class Form1 : Form
    {
        Process p = new Process();
        ProcessStartInfo info = new ProcessStartInfo();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            info.FileName = "cmd.exe";
            info.RedirectStandardInput = true;
            info.RedirectStandardOutput = true;
            info.RedirectStandardError = true;
            info.UseShellExecute = false;
            info.CreateNoWindow = true;

            p.StartInfo = info;
            p.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (StreamWriter sw = p.StandardInput)
            {
                if (sw.BaseStream.CanWrite)
                {
                    sw.WriteLine(textBox1.Text);
                }
            }
            textBox2.Text = p.StandardOutput.ReadToEnd();
            textBox3.Text = p.StandardError.ReadToEnd();
            p.WaitForExit();
        }
    }
}
