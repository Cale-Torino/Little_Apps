using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CrypterAIO
{
    public partial class Form4 : Form
    {
        public string _theme;
        public Form4()
        {
            InitializeComponent();           
        }
        private void Loading()
        {
            //Checking For Application Updates...
            Text = "Checking For Application Updates...";
            label4.Text = "Checking For Application Updates...";
            button1.Visible = false;
            button2.Visible = false;
            linkLabel1.Visible = false;
            progressBar1.Visible = true;
            timer1.Tick += new EventHandler(TimerEventProcessor);
            timer1.Interval = 5000;
            timer1.Start();
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            if (_theme == "LavenderTheme")
            {
                button1.BackColor = Color.FromArgb(187, 134, 252);
                button2.BackColor = Color.FromArgb(187, 134, 252);
                linkLabel1.LinkColor = Color.FromArgb(187, 134, 252);
            }
            else if (_theme == "JadeTheme")
            {
                button1.BackColor = Color.FromArgb(0, 168, 107);
                button2.BackColor = Color.FromArgb(0, 168, 107);
                linkLabel1.LinkColor = Color.FromArgb(0, 168, 107);
            }
            else if (_theme == "SkyTheme")
            {
                button1.BackColor = Color.FromArgb(0, 122, 204);
                button2.BackColor = Color.FromArgb(0, 122, 204);
                linkLabel1.LinkColor = Color.FromArgb(0, 122, 204);
            }
            else if (_theme == "CrimsonTheme")
            {
                button1.BackColor = Color.FromArgb(221, 0, 49);
                button2.BackColor = Color.FromArgb(221, 0, 49);
                linkLabel1.LinkColor = Color.FromArgb(221, 0, 49);
            }
            Loading();
        }

        public void TimerEventProcessor(object sender, EventArgs e)
        {
            try
            {
                timer1.Stop();
                progressBar1.Visible = false;
                button1.Visible = true;
                button2.Visible = true;
                linkLabel1.Visible = true;
                //You Have The Latest Version!
                Text = "Updates Are Available.";
                label4.Text = "Updates Are Available.";
                //MessageBox.Show("No Updates Available For The Trial Version", "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Information);
                //Close();
            }
            catch (Exception)
            {
                label4.Text = "Can't connect to server...";
                //MessageBox.Show("Can't connect to server...", "NOTICE", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                //Close();
                return;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Loading();
        }
    }
}
