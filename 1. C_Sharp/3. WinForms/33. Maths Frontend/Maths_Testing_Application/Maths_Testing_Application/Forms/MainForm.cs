using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Maths_Testing_Application.LoggerClass;
using static Maths_Testing_Application.SystemClass;

namespace Maths_Testing_Application
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            CreateFolder();
            tabControl1.TabPages.Remove(tabPage4);
            Logger.WriteLine(" *** MainForm has loaded: [MainForm_Load] ***");
            richTextBox.AppendText($"[{DateTime.Now}] : Application Started" + Environment.NewLine);
        }

        private void CreateFolder()
        {
            try
            {
                //Create the folders used by the app
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + @"\Logs");
                Logger.WriteLine(" *** Application Start [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Application Start" + Environment.NewLine);
                Logger.WriteLine(" *** CreateDirectory Success [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Logs Create Directory Success" + Environment.NewLine);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                //Logs_richTextBox.AppendText("[" + DateTime.Now.ToString() + "] : Error:" + ex.Message + Environment.NewLine);
                return;
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open the about form
            Form f = new AboutForm();
            f.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox.AppendText(DeviceSpecs.OSsys() + Environment.NewLine);
            richTextBox.AppendText(DeviceSpecs.GetAll() + Environment.NewLine);
        }

        private void Nextbutton_Click(object sender, EventArgs e)
        {
            tabControl1.SelectTab(1);
        }

        private void StartTestbutton_Click(object sender, EventArgs e)
        {
            tabControl1.SelectTab(2);  // 0-based index, this shows the second tab
        }

        private void Nextquestionbutton1_Click(object sender, EventArgs e)
        {
            tabControl1.TabPages.Remove(tabPage3);
            tabControl1.TabPages.Add(tabPage4);
            tabControl1.SelectTab(tabPage4);
        }

        private void Nextquestionbutton2_Click(object sender, EventArgs e)
        {

        }

        private void Backbutton2_Click(object sender, EventArgs e)
        {
            tabControl1.TabPages.Remove(tabPage4);
            tabControl1.TabPages.Add(tabPage3);
            tabControl1.SelectTab(tabPage3);
        }
    }
}
