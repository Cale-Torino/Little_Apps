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
    public partial class Form3 : Form
    {
        public bool _allowExit;//global
        public string _theme;
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Closing += new CancelEventHandler(Form3_Closing);
            _allowExit = true;//global
            Environment.Exit(0);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Closing += new CancelEventHandler(Form3_Closing);
            _allowExit = false;//global
            Close();
        }
        private void Form3_Closing(object sender, CancelEventArgs e)
        {
            if (!_allowExit)
            {
                e.Cancel = false;
            }
            else
            {
                e.Cancel = false;
            }
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            if (_theme == "LavenderTheme")
            {
                button1.BackColor = Color.FromArgb(187, 134, 252);
                button2.BackColor = Color.FromArgb(187, 134, 252);
            }
            else if (_theme == "JadeTheme")
            {
                button1.BackColor = Color.FromArgb(0, 168, 107);
                button2.BackColor = Color.FromArgb(0, 168, 107);
            }
            else if (_theme == "SkyTheme")
            {
                button1.BackColor = Color.FromArgb(0, 122, 204);
                button2.BackColor = Color.FromArgb(0, 122, 204);
            }
            else if (_theme == "CrimsonTheme")
            {
                button1.BackColor = Color.FromArgb(221, 0, 49);
                button2.BackColor = Color.FromArgb(221, 0, 49);
            }
        }
    }
}
