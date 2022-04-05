using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ListViewStyle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            // removes the ugly dotted line around focused item
            ListViewImprovedClass.SendMessage(Handle, 0x127, ListViewImprovedClass.MakeLong(1, 0x1), 0);
            ListViewImprovedClass.SetWindowTheme(listView1.Handle, "Explorer", null);
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            
        }
    }
}
