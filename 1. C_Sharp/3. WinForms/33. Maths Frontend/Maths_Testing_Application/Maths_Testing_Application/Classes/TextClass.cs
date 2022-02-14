using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maths_Testing_Application
{
    internal class TextClass
    {
        public static class EngLan
        {
            public static void HomeText(Label L)
            {
                try
                {
                    L.Text = "Maths Testing Application";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add HomeText", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

        }

        public static class AfriLan
        {
            public static void HomeText(Label L)
            {
                try
                {
                    L.Text = "Wiskunde Toets Aansoek";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add HomeText", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
        }

    }
}
