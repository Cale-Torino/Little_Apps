using System;
using System.Runtime.InteropServices;

namespace ListViewStyle
{
    public class ListViewImprovedClass
    {
        //https://stackoverflow.com/questions/2691726/how-can-i-remove-the-selection-border-on-a-listviewitem
        [DllImport("uxtheme.dll", ExactSpelling = true, CharSet = CharSet.Unicode)]
        public static extern int SetWindowTheme(IntPtr hwnd, string pszSubAppName, string pszSubIdList);

        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

        public static int MakeLong(int wLow, int wHigh)
        {
            int low = IntLoWord(wLow);
            short high = IntLoWord(wHigh);
            int product = 0x10000 * high;
            int mkLong = low | product;
            return mkLong;
        }

        public static short IntLoWord(int word)
        {
            return (short)(word & short.MaxValue);
        }
    }
}
