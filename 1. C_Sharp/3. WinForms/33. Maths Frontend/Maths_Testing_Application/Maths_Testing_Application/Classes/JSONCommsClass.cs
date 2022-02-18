using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maths_Testing_Application
{
    internal class JSONCommsClass
    {
        public static class JSONSending
        {
            public static string JSONFormat(string Msg)
            {
                try
                {
                    string jSon = "{\"MachineName\":\"" + Environment.MachineName +
                    "\",\"Message\":\"" + Msg +
                    "\",\"UserName\":\"" + Environment.UserName +
                    "\",\"DateTime\":\"" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + "\"}";
                    return jSon;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add HomeText", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return "error";
                }
            }

        }
    }
}
