using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace quick1080ptest
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Thread t = new Thread(new ThreadStart(DoSplash));// Point to method
            t.Start();// Start splash thread
            Thread.Sleep(1000);// 1 second
            t.Abort();// Stop splash thread
            Thread.Sleep(200);// 0.2 second
            Application.Run(new MainForm());
        }

        private static void DoSplash()
        {
            // Show splash form
            SplashForm f = new SplashForm();
            f.ShowDialog();
        }
    }
}
