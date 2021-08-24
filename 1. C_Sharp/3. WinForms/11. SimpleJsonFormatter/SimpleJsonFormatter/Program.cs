using System;
using System.Windows.Forms;

namespace SimpleJsonFormatter
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            if (Environment.OSVersion.Version.Major >= 6) SetProcessDPIAware();//set for 4k
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
        [System.Runtime.InteropServices.DllImport("user32.dll")]//set for 4k
        private static extern bool SetProcessDPIAware();//set for 4k
    }
}
