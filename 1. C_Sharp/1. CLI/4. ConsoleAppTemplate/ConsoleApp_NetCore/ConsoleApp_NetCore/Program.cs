using System;
using System.IO;

namespace ConsoleApp_NetCore
{
    class Program
    {
        static void Main(string[] args)
        {
            Directory.CreateDirectory(AppDomain.CurrentDomain.BaseDirectory + @"\Logs");
            LogClass.WriteLine("Application Start");
            ComputerClass.GetData();
            Console.WriteLine($"parameter count = {args.Length}");
            for (int i = 0; i < args.Length; i++)
            {
                Console.WriteLine($"Arg[{i}] = [{args[i]}]");
            }
            Console.ReadKey();
        }
    }
}
