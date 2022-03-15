using System;
using System.Reflection;

namespace ConsoleAppTemplate
{
    public static class ComputerClass
    {
        public static void GetData() 
        {
            Console.WriteLine($"--------------------------------------------");
            Console.WriteLine($"==== Get PC Specs ==========================");
            Console.WriteLine($"Get All The PC Specs");
            Console.WriteLine($"--------------------------------------------");
            Console.WriteLine($"UserName: {Environment.UserName}");
            Console.WriteLine($"MachineName: {Environment.MachineName}");
            Console.WriteLine($"UserDomainName: {Environment.UserDomainName}");
            Console.WriteLine($"ProcessorCount: {Environment.ProcessorCount}");
            Console.WriteLine($"CurrentDirectory: {Environment.CurrentDirectory}");
            Console.WriteLine($"Is64BitOperatingSystem: {Environment.Is64BitOperatingSystem}");
            Console.WriteLine($"OSVersion: {Environment.OSVersion}");
            Console.WriteLine($"SystemDirectory: {Environment.SystemDirectory}");
            Console.WriteLine($"TickCount: {Environment.TickCount}");
            Console.WriteLine($"Version: {Environment.Version}");
            Console.WriteLine($"WorkingSet: {Environment.WorkingSet}");
            Console.WriteLine($"App Version: {Assembly.GetExecutingAssembly().GetName().Version}");
            Console.WriteLine($"App Name: {Assembly.GetExecutingAssembly().GetName().Name}");
            Console.WriteLine($"App FullName: {Assembly.GetExecutingAssembly().GetName().FullName}");
            Console.WriteLine($"--------------------------------------------");
        }

    }
}
