using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using Timer = System.Timers.Timer;

namespace HL2_Media
{
    public partial class SplashForm : Form
    {
        public SplashForm()
        {
            InitializeComponent();
        }
        Timer myTimer = new Timer();
        private void SplashForm_Load(object sender, EventArgs e)
        {
            label2.Text = "Version: " + Application.ProductVersion;//Get version from AssemblyInfo.cs [assembly: AssemblyFileVersion("1.0.1")]

            myTimer.Elapsed += new ElapsedEventHandler(TimeUp);
            myTimer.Interval = 3000;
            myTimer.Start();//start timer
        }

        public void TimeUp(object source, ElapsedEventArgs e)
        {
            Invoke((MethodInvoker)delegate
            {
                // close the form on the forms thread
                Close();
                myTimer.Stop();
            });
        }

    }
}
