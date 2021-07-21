using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Timers;
using System.Windows.Forms;
using static quick1080ptest.LoggerClass;
using Timer = System.Timers.Timer;

namespace quick1080ptest
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Initiate the app by calling the methods within
        /// </summary>
        private void Ini()
        {
            try
            {
                //Initiate the app by calling these methods
                string FileName = Application.StartupPath + @"\" + "temp.log";
                if (File.Exists(FileName))
                {
                    File.Delete(FileName);
                }
                CreateFolder();
                Logger.WriteLine(" *** Ini Complete [SplashForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ini Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [SplashForm] ***");
                return;
            }
        }

        private void CreateFolder()
        {
            try
            {
                //Create the folders used by the app
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + @"\Logs");
                Logger.WriteLine(" *** Application Start [SplashForm] ***");
                Logger.WriteLine(" *** CreateDirectory Success [SplashForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [SplashForm] ***");
                return;
            }
        }
        public void WriteToLog(string _text)
        {
            string[] lines = new string[] { DateTime.Now.ToString() + " : " + _text };
            File.AppendAllLines(@"temp.log", lines);
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            Ini();
            WriteToLog("Ini Complete");
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            Location = new Point((Screen.PrimaryScreen.WorkingArea.Width - Width) / 2,(Screen.PrimaryScreen.WorkingArea.Height - Height) / 2);
            MinimizeBox = false;
            Text = "quick1080ptest - Ver:" + Application.ProductVersion;
            button1.Enabled = false;
            toolStripStatusLabel1.Text = "Application - Ver:" + Application.ProductVersion;
            WriteToLog("App Ready");
        }
    }
}
