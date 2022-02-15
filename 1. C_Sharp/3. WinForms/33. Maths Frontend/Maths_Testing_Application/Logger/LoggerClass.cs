using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    public class LoggerClass
    {
        public static class Logger
        {
            //Create logfile log. file
            private static string assemblyFolder = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            private static string LogFile = assemblyFolder + @"\Logs\Maths_Testing_Application_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log";
            private static FileStream fs = File.Create(LogFile);
            //private static string assemblyFolder = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            //private static string LogFile = Path.Combine(assemblyFolder, @"\Logs\Maths_Testing_Application_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log");
            //private static string LogFile = Application.StartupPath + @"\Logs\Maths_Testing_Application_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log";

            public static int WriteLine(string txt)
            {
                try
                {
                    //Write to the logfile
                    File.AppendAllText(LogFile, "[" + DateTime.Now.ToString() + "] : " + txt + "\n");
                    return 0;
                }
                catch (Exception ex)
                {
                    //MessageBox.Show(ex.Message, "Could Not Append Text To Log File", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return -1;
                }
            }

            public static int DeleteLog()
            {
                try
                {
                    //Delete the log file
                    File.Delete(LogFile);
                    return 0;
                }
                catch (Exception ex)
                {
                    //MessageBox.Show(ex.Message, "Could Not Delete Log File", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return -1;
                }
            }
        }
    }
}
