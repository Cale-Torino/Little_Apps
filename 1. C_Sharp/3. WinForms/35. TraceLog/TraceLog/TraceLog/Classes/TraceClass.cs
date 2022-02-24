using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TraceLog
{
    public static class TraceClass
    {
        /// <summary>
        /// Gets the path to write a log to
        /// </summary>
        public static string GetLogPath()
        {
            Directory.CreateDirectory(AppDomain.CurrentDomain.BaseDirectory + @"\Logs");
            using (Process p = Process.GetCurrentProcess())
            {
                return $"{AppDomain.CurrentDomain.BaseDirectory}\\Logs\\{p.ProcessName}_{DateTime.Now:yyyy-dd-M--HH-mm-ss}.txt";
                //return $"{Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location)}\\Logs\\Output_{DateTime.Now:yyyy-dd-M--HH-mm-ss}.txt";
            }
        }
        /// <summary>
        /// returnes the TextWriterTraceListener variable
        /// </summary>
        public static TextWriterTraceListener GetTraceListenerh(string path) 
        {
            return new TextWriterTraceListener(File.CreateText(path));
        }

        /// <summary>
        /// Writes the log file in VS output and to a file, 0=Info; 1=Warning; 2=Error; 3=Debug;
        /// </summary>
        public static void LogWrite(string data, int i)
        {
            switch (i)
            {
                case 0:
                    Trace.WriteLine($"{data}", $"[{DateTime.Now}] | Info   ");
                    Trace.Flush();
                    break;
                case 1:
                    Trace.WriteLine($"{data}", $"[{DateTime.Now}] | Warning");
                    Trace.Flush();
                    break;
                case 2:
                    Trace.WriteLine($"{data}", $"[{DateTime.Now}] | Error  ");
                    Trace.Flush();
                    break;
                case 3:
                    Trace.WriteLine($"{data}", $"[{DateTime.Now}] | Debug  ");
                    Trace.Flush();
                    break;
                default:
                    break;
            }

        }
    }
}
