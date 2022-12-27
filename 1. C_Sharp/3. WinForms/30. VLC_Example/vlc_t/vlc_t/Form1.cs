using System;
using System.Windows.Forms;
using Vlc.DotNet.Forms;

namespace vlc_t
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //vlcControl1.Play(new Uri("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
        }
        /*
        private void vlcControl_VlcLibDirectoryNeeded(object sender, VlcLibDirectoryNeededEventArgs e)
        {
            var currentAssembly = Assembly.GetEntryAssembly();
            var currentDirectory = new FileInfo(currentAssembly.Location).DirectoryName;
            // Default installation path of VideoLAN.LibVLC.Windows
            e.VlcLibDirectory = new DirectoryInfo(Path.Combine(currentDirectory, "libvlc", IntPtr.Size == 4 ? "win-x86" : "win-x64"));
        }
        */
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            vlcControl1.Play(new Uri("https://github.com/Cale-Torino/Little_Apps/raw/main/1.%20C_Sharp/3.%20WinForms/30.%20VLC_Example/vlc_t/vlc_t/media/big_buck_bunny_480p_surround-fix.avi.mp4"));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (button3.Text == "Pause")
            {
                vlcControl1.Pause();
                button3.Text = "Play";
            }
            else if (button3.Text == "Play")
            {
                vlcControl1.Pause();
                button3.Text = "Pause";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            vlcControl1.Stop();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //vlcControl1.Video.AspectRatio = "16.9";
            vlcControl1.Focus();
            vlcControl1.Video.FullScreen = true;
            vlcControl1.Update();
        }
    }
}
