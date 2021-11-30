using dll_example_class_library;
using System;
using System.IO;
using System.Windows.Forms;

namespace dll_example
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                //calculate
                Class1 dll_example_class_library = new Class1();
                int _result = dll_example_class_library.Calculate(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value));
                _Logger.WriteLine("***Result: " + _result.ToString(), LogFile);
                MessageBox.Show(_result.ToString(), "The Result Is", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "An Error Occured Reading The DLL", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //about
            _Logger.WriteLine("***About Clicked***", LogFile);
            Form f2 = new Form2();
            f2.ShowDialog();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //exit
            _Logger.WriteLine("***Exit Clicked***", LogFile);
            Application.Exit();
        }
        private static string LogFile;
        Logger _Logger;
        private void CreateFolder()
        {
            try
            {
                //CreatFolder
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + "\\Logs");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //form load
            try
            {
                LogFile = Application.StartupPath + "\\Logs\\DLL_Example_Logger_" + DateTime.Now.ToString("yyyy-dd-M") + ".log";
                 _Logger = new Logger();
                 CreateFolder();
                _Logger.WriteLine("***Application Start***", LogFile);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Application Start Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //delete log
            try
            {
                _Logger.WriteLine("***Delete Log***", LogFile);
                string _result =_Logger.DeleteLog(LogFile);
                MessageBox.Show(_result, "Delete Log", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Delete Log Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }
    }
}
