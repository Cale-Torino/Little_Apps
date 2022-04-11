using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Nyan
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            //Opacity = 0.50;
        }

        private void pictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                MoveFormClass.ReleaseCapture();
                MoveFormClass.SendMessage(Handle, MoveFormClass.WM_NCLBUTTONDOWN, MoveFormClass.HT_CAPTION, 0);
            }
        }
    }
}
