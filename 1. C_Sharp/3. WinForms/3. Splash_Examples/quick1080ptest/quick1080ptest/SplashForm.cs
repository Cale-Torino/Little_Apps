﻿using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using static quick1080ptest.LoggerClass;
using Timer = System.Timers.Timer;

namespace quick1080ptest
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
            label2.Text = Application.ProductVersion;//Get version from AssemblyInfo.cs [assembly: AssemblyFileVersion("1.0.1")]
            
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
