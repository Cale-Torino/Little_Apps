using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Playing_MP3
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            PlayOnce();
        }
        //https://docs.microsoft.com/en-us/windows/win32/multimedia/mci
        [DllImport("winmm.dll")]
        public static extern uint mciSendString(string lpstrCommand, StringBuilder lpstrReturnString, int uReturnLength, IntPtr hWndCallback);
        private void Playbutton_Click(object sender, EventArgs e)
        {
            PlayRepeat();
        }
        private static string _Status()
        {
            StringBuilder sBuffer = new StringBuilder(128);
            mciSendString("status temp_alias mode", sBuffer, sBuffer.Capacity, IntPtr.Zero);
            return sBuffer.ToString();
        }
        private void Stopbutton_Click(object sender, EventArgs e)
        {
            mciSendString(@"close temp_alias", null, 0, IntPtr.Zero);
        }

        private void Statusbutton_Click(object sender, EventArgs e)
        {
            label.Text = _Status();
        }
        private void PlayRepeat()
        {
            mciSendString(@"close temp_alias", null, 0, IntPtr.Zero);
            mciSendString(@"open ""next-chapter-piano-ident-21438.mp3"" alias temp_alias", null, 0, IntPtr.Zero);
            mciSendString("play temp_alias repeat", null, 0, IntPtr.Zero);
        }
        private void PlayOnce()
        {
            mciSendString(@"close temp_alias", null, 0, IntPtr.Zero);
            mciSendString(@"open ""next-chapter-piano-ident-21438.mp3"" alias temp_alias", null, 0, IntPtr.Zero);
            mciSendString("play temp_alias", null, 0, IntPtr.Zero);
        }

        private void PlayOncebutton_Click(object sender, EventArgs e)
        {
            PlayOnce();
        }
    }
}
