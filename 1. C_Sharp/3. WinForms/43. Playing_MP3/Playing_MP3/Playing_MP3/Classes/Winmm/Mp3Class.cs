using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Playing_MP3
{
    public class Mp3Class : IDisposable
    {
        [DllImport("winmm.dll")]
        public static extern uint mciSendString(string lpstrCommand, StringBuilder lpstrReturnString, int uReturnLength, IntPtr hWndCallback);

        public Mp3Class(string filename)
        {
            //@"open ""Music\theme.mp3"" type mp3 alias temp_alias"
            string f = $@"open ""{filename}"" type mpegvideo alias temp_alias";
            //MessageBox.Show(f);
            CheckMCIResult(mciSendString(f, null, 0, IntPtr.Zero));
        }
        public void PlayRepeat()
        {
            string f = $@"play temp_alias repeat";
            CheckMCIResult(mciSendString(f, null, 0, IntPtr.Zero));
        }
        public void Play()
        {
            string f = $@"play temp_alias";
            CheckMCIResult(mciSendString(f, null, 0, IntPtr.Zero));
        }
        public void Stop()
        {
            string f = $@"stop temp_alias";
            CheckMCIResult(mciSendString(f, null, 0, IntPtr.Zero));
        }
        private static void CheckMCIResult(long code)
        {
            int err = (int)(code & 0xffffffff);
            if (err != 0)
            {
                throw new Exception(string.Format("MCI error {0}", err));
            }
        }

        public void Dispose()
        {
            mciSendString(@"close temp_alias", null, 0, IntPtr.Zero);
            //throw new NotImplementedException();
        }
    }
}
