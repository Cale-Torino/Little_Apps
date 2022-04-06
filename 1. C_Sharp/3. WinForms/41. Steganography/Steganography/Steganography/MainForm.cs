using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Steganography
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            string sourceDir = $"{AppDomain.CurrentDomain.BaseDirectory}\\app";
            string destDir = $"{AppDomain.CurrentDomain.BaseDirectory}\\done";
            Directory.CreateDirectory(sourceDir);
            Directory.CreateDirectory(destDir);
        }

        public int CMDStartServer(string CMD_command, string CMD_workingdir)
        {
            try
            {
                var p = new ProcessStartInfo();
                p.UseShellExecute = true;//use the OS shell
                p.WorkingDirectory = CMD_workingdir;//C:\Windows\System32
                p.FileName = @"C:\Windows\System32\cmd.exe";//find cmd location
                //p.Verb = "runas";//run as admin
                p.Arguments = CMD_command;//set your cmd command
                p.WindowStyle = ProcessWindowStyle.Normal;//show the window `Normal` or `Hidden` to hide.
                Process _Process = Process.Start(p);//Initiate the process
                return _Process.Id;//Return PID
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Could not run command successfully", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return 1;
            }
        }

        private void Mergebutton_Click(object sender, EventArgs e)
        {
            try
            {
                string sourceDir = $"{AppDomain.CurrentDomain.BaseDirectory}\\app";
                string destDir = $"{AppDomain.CurrentDomain.BaseDirectory}\\done";
                if (!File.Exists("foldername.zip"))
                {
                    ZipFile.CreateFromDirectory(sourceDir, "foldername.zip");
                }

                //CMDStartServer($"/k ipconfig", @"C:\Users\User48\source\repos\Steganography\Steganography\bin\Debug");
                CMDStartServer($"/k copy /b picture.png + foldername.zip outputfilename.jpg", AppDomain.CurrentDomain.BaseDirectory);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }
        }

        private void Extractbutton_Click(object sender, EventArgs e)
        {
            try
            {
                string sourceDir = $"{AppDomain.CurrentDomain.BaseDirectory}";
                string destDir = $"{AppDomain.CurrentDomain.BaseDirectory}done";
                string fName = "picture.png";
                CMDStartServer($"/k ren outputfilename.jpg outputfilename.zip", AppDomain.CurrentDomain.BaseDirectory);
                ZipFile.ExtractToDirectory(sourceDir + fName, destDir);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                return;
            }
        }
    }
}
