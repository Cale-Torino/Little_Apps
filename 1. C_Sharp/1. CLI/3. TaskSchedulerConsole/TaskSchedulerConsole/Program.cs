using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using static TaskSchedulerConsole.LoggerClass;

namespace TaskSchedulerConsole
{
    class Program
    {
        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        [DllImport("kernel32.dll")]
        static extern IntPtr GetConsoleWindow();

        static void Main(string[] args)
        {
            //https://github.com/dahall/taskscheduler
            //https://github.com/dahall/TaskScheduler/wiki
            //ShowConsole();
            //HideConsole();
            AboutClass AC = new AboutClass();
            AC.Author_Details();
            IniApp();
            Console.ReadKey();
        }
        private static void HideConsole()
        {
            try
            {
                var handle = GetConsoleWindow();
                ShowWindow(handle, 0);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(" *** Error:" + ex.Message + " [HideConsole Error] ***");
                Console.WriteLine($"[{DateTime.Now}] => HideConsole Error");
                //Console.ReadKey();
                return;
            }
        }
        private static void ShowConsole()
        {
            try
            {
                var handle = GetConsoleWindow();
                ShowWindow(handle, 5);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(" *** Error:" + ex.Message + " [ShowConsole Error] ***");
                Console.WriteLine($"[{DateTime.Now}] => ShowConsole Error");
                //Console.ReadKey();
                return;
            }
        }
        private static void IniApp()
        {
            try
            {
                //Initiate the app by calling these methods
                CreateFolder();
                Logger.WriteLine(" *** Ini Complete [MainForm] ***");
                Console.WriteLine($"[{DateTime.Now}] => Ini Complete");
                //Console.ReadKey();
            }
            catch (Exception ex)
            {
                Logger.WriteLine(" *** Error:" + ex.Message + " [IniError] ***");
                Console.WriteLine($"[{DateTime.Now}] => IniError");
                //Console.ReadKey();
                return;
            }
        }
        private static void CreateFolder()
        {
            try
            {
                //Create the folders used by the app
                string path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
                Directory.CreateDirectory(path + @"\Logs");
                Logger.WriteLine(" *** Application Start [Main] ***");
                Console.WriteLine($"[{DateTime.Now}] => Application Start");
                Logger.WriteLine(" *** CreateDirectory Success [MainForm] ***");
                //Console.ReadKey();
            }
            catch (Exception ex)
            {
                Logger.WriteLine(" *** Error:" + ex.Message + " [CreateFolderError] ***");
                return;
            }
        }
    }
}
