using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dll_example_class_library
{
    public class Class1
    {
        public int Calculate(int Fint, int Sint)
        {
            //logger calculate
            int _result = Fint + Sint;
            return _result;
        }
    }
    public class Logger
    {
        public string WriteLine(string txt, string LogFile)
        {
            //logger writeline
            try
            {
                File.AppendAllText(LogFile, "[" + DateTime.Now.ToString() + "] : " + txt + "\n");
                return "[" + DateTime.Now.ToString() + "] : " + txt + "\n";
            }
            catch (Exception ex)
            {
                return ex.Message + " => Could Not Append Text To Log File";
            }
        }

        public string DeleteLog(string LogFile)
        {
            //logger delete log
            try
            {
                File.Delete(LogFile);
                return "[" + DateTime.Now.ToString() + "] : Delete Success" + "\n";
            }
            catch (Exception ex)
            {
                return ex.Message + " => Could Not Delete Log File";
            }
        }
    }
}
