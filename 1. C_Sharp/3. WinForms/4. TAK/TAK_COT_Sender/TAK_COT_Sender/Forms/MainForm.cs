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
using static TAK_COT_Sender.LoggerClass;

namespace TAK_COT_Sender
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        private void Ini()
        {
            try
            {
                //Initiate the app by calling these methods
                CreateFolder();
                Logger.WriteLine(" *** Ini Complete [MainForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ini Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
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
                Logger.WriteLine(" *** Application Start [MainForm] ***");
                Logger.WriteLine(" *** CreateDirectory Success [MainForm] ***");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Logger.WriteLine(" *** Error:" + ex.Message + " [MainForm] ***");
                return;
            }
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            Ini();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
