using System;
using System.IO;

namespace TaskSchedulerConsole
{
    class LoggerClass
    {
        public static class Logger
        {
            //Create logfile log. file
            private static string LogFile = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location) + @"\Logs\TaskSchedulerConsole_" + DateTime.Now.ToString("yyyy-dd-M--HH-mm-ss") + ".log";

            public static void WriteLine(string txt)
            {
                try
                {
                    //Write to the logfile
                    File.AppendAllText(LogFile, "[" + DateTime.Now.ToString() + "] : " + txt + "\n");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Could Not Append Text To Log File \n {ex}");
                    //Console.ReadKey();
                    return;
                }
            }

            public static void DeleteLog()
            {
                try
                {
                    //Delete the log file
                    File.Delete(LogFile);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Could Not Delete Log File \n {ex}");
                    //Console.ReadKey();
                    return;
                }
            }
        }
    }
}
