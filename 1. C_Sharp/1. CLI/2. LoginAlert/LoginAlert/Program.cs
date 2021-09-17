using System;
using System.IO;
using System.Net.Http;
using System.Runtime.InteropServices;
using static LoginAlert.LoggerClass;

namespace LoginAlert
{
    class Program
    {
        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        [DllImport("kernel32.dll")]
        static extern IntPtr GetConsoleWindow();

        const int SW_HIDE = 0;
        const int SW_SHOW = 5;
        static void Main(string[] args)
        {
            HideConsole();
            //ShowConsole();
            //Console.WriteLine($"[{DateTime.Now}] => {Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)}");
            //Console.ReadKey();
            IniApp();
            RunHTTPQuery();
        }
        private static void HideConsole()
        {
            try
            {
                var handle = GetConsoleWindow();
                ShowWindow(handle, SW_HIDE);
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
                ShowWindow(handle, SW_SHOW);
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
                string path = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
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
        private static void RunHTTPQuery()
        {
            using (HttpClient client = new HttpClient())
            {
                try
                {
                    HttpResponseMessage response = client.GetAsync("https://api.telegram.org/botYOUR_TOKEN_HERE/sendMessage?chat_id=-YOUR_CHAT_ID_HERE&parse_mode=HTML&text=%F0%9F%9A%A8+<b>Alert</b>%0A<i>+64.42.181.26</i><u>+USDedicated+Server</u>%0A" + Environment.MachineName + "+" + Environment.UserName + "%0ALogin+to+server+at+this+servertime+[" + DateTime.Now + "]").Result;
                    if (response.IsSuccessStatusCode)
                    {
                        Console.WriteLine($"Result: {response.Content.ReadAsStringAsync().Result} ");
                        Logger.WriteLine($"Result: {response.Content.ReadAsStringAsync().Result} [TelegramSend]");
                        //Console.ReadKey();
                    }
                    else
                    {
                        Console.WriteLine($"StatusCode: {(int)response.StatusCode} ReasonPhrase:{response.ReasonPhrase} ");
                        Logger.WriteLine($"StatusCode: {(int)response.StatusCode} ReasonPhrase:{response.ReasonPhrase} [TelegramSend] ***");
                        //Console.ReadKey();
                    }
                }
                catch (Exception ex)
                {
                    Logger.WriteLine(" *** Error:" + ex.Message + " [TelegramSendError] ***");
                    Console.WriteLine($"[{DateTime.Now}] => TelegramSend error");
                    //Console.ReadKey();
                    return;
                }
            }
        }
    }
}
