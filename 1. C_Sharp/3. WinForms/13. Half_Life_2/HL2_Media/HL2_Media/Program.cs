using System;
using System.Threading;
using System.Windows.Forms;

namespace HL2_Media
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
            Thread.Sleep(3000);// 3 seconds
            Application.Run(new MainForm());
        }

        private static void DoSplash()
        {
            // Show splash form
            Application.Run(new SplashForm());
        }
    }
}
