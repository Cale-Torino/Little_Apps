using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cursor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.Rows.Add("1", "1XX", "1test");
            dataGridView1.Rows.Add("2", "2XX", "2test");
            dataGridView1.Rows.Add("3", "3XX", "3test");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TrySetCursorsDotHandToSystemHandCursor(1);
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipText = "Old cursor selected.";
            notifyIcon1.ShowBalloonTip(1000);
        }
        private static int TrySetCursorsDotHandToSystemHandCursor(int i)
        {
            if (i==0)
            {
                try
                {
                    typeof(Cursors).GetField("hand", BindingFlags.Static | BindingFlags.NonPublic)
                                   .SetValue(null, IDC_HAND);
                }
                catch { MessageBox.Show("SystemHandCursorNew error"); }
            }
            else
            {
                try
                {
                    typeof(Cursors).GetField("hand", BindingFlags.Static | BindingFlags.NonPublic)
                                   .SetValue(null, IDC_APPSTARTING);
                }
                catch { MessageBox.Show("SystemHandCursorOld error"); }
            }
            return 0;
        }

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern IntPtr LoadCursor(IntPtr hInstance, int lpCursorName);

        private static readonly Cursor IDC_HAND = new Cursor(LoadCursor(IntPtr.Zero, 32649 /*IDC_HAND*/));

        private static readonly Cursor IDC_APPSTARTING = new Cursor(LoadCursor(IntPtr.Zero, 32650 /*IDC_APPSTARTING*/));


        private void button3_Click(object sender, EventArgs e)
        {
            TrySetCursorsDotHandToSystemHandCursor(0);
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipText = "Default windows 10 system cursor selected.";
            notifyIcon1.ShowBalloonTip(1000);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.ShowDialog();
            
        }
    }
}
