using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static quick1080ptest.LoggerClass;

namespace quick1080ptest
{
    public partial class SplashForm : Form
    {
        public SplashForm()
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
                CreateFolder();
                Sleepp();
                OpenForm();
                Logger.WriteLine(" *** Ini Complete [SplashForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ini Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [SplashForm] ***");
                return;
            }
        }

        private async void Sleepp()
        {
            try
            {
                //Create the folders used by the app
                Logger.WriteLine(" *** Sleeping Start [SplashForm] ***");
                await Task.Delay(5000);
                //Thread.Sleep(5000);
                Logger.WriteLine(" *** Sleeping End [SplashForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
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
                Directory.CreateDirectory(path + "\\Logs");
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

        private void OpenForm()
        {
            try
            {
                //Open the Main Form
                Logger.WriteLine(" *** Open Main Form [SplashForm] ***");
                Form f = new MainForm();
                //Hide();
                f.ShowDialog();
                Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Open Main Form Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [SplashForm] ***");
                return;
            }
        }

        private void SplashForm_Load(object sender, EventArgs e)
        {
            Ini();
        }
    }
}
