using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp_NetCore
{
    public static class LogClass
    {
        private static readonly string LogFile = AppDomain.CurrentDomain.BaseDirectory + @"\Logs\" + Assembly.GetExecutingAssembly().GetName().Name + "_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log";

        public static void WriteLine(string txt)
        {
            try
            {
                File.AppendAllText(LogFile, "[" + DateTime.Now.ToString() + "] : " + txt + "\n");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return;
            }
        }

        public static void DeleteLog()
        {
            try
            {
                File.Delete(LogFile);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return;
            }
        }
    }
}
