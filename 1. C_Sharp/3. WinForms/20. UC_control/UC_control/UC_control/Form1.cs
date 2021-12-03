using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UC_control
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Image = Properties.Resources.w32;
            button2.BackColor = default;
            button1.BackColor = Color.Black;
            button2.Image = null;
            panel3.Controls.Clear();
            UserControl1 UC1 = new UserControl1();
            panel3.Controls.Add(UC1);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            button1.Image = null;
            button2.BackColor = Color.Black;
            button1.BackColor = default;
            button2.Image = Properties.Resources.w32;
            panel3.Controls.Clear();
            UserControl2 UC2 = new UserControl2();
            panel3.Controls.Add(UC2);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button1.Image = Properties.Resources.w32;
        }
    }
}
