using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CrypterAIO
{
    public class JadeTheme
    {
        public class MyRenderer : ToolStripProfessionalRenderer
        {
            public MyRenderer() : base(new MyColors()) { }
        }

        private class MyColors : ProfessionalColorTable
        {
            public override Color MenuItemSelected
            {
                get { return Color.FromArgb(0, 168, 107); }//color grey blue highlights mix org + yell
            }
            public override Color MenuItemSelectedGradientBegin
            {
                get { return Color.FromArgb(0, 168, 107); }
            }
            public override Color MenuItemSelectedGradientEnd
            {
                get { return Color.FromArgb(0, 168, 107); }
            }
            public override Color MenuItemPressedGradientBegin
            {
                get { return Color.FromArgb(0, 168, 107); }
            }
            public override Color MenuItemPressedGradientMiddle
            {
                get { return Color.FromArgb(0, 168, 107); }
            }
            public override Color MenuItemPressedGradientEnd
            {
                get { return Color.FromArgb(0, 168, 107); }
            }
        }
    }
}
