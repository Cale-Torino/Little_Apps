using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    public class LoggerClass
    {
        public static class Logger
        {
            //Create logfile log. file
            private static readonly string LogFile = AppDomain.CurrentDomain.BaseDirectory + @"Logs\" + AppDomain.CurrentDomain.FriendlyName + "_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log";

            public static int WriteLine(string txt)
            {
                try
                {
                    //Write to the logfile
                    File.AppendAllText(LogFile, "[" + DateTime.Now.ToString() + "] : " + txt + "\n");
                    return 0;
                }
                catch (Exception)
                {
                    return -1;//error
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
                catch (Exception)
                {
                    return -1;//error
                }
            }
        }
    }
}
