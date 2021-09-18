using System;
using System.IO;
using System.Reflection;

namespace TaskSchedulerConsole
{
    class AboutClass
    {
        public void Author_Details()
        {
            Console.WriteLine($"[{DateTime.Now}] => {Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location)}");
            Console.WriteLine($"");
            Console.WriteLine($"             _ _ _ _ ||_TaskSchedulerConsole_ _ _ _ _ _ _");
            Console.WriteLine($"             \\  _  _ ||  _  _ _ ___");
            Console.WriteLine($"             / /__/ \\|| |_/");
            Console.WriteLine($"            / __   / || -  _ ___");
            Console.WriteLine($"           / /  / /  ||/ /");
            Console.WriteLine($"   _ _ _ _/ /  /  \\_/||  \\_ ______");
            Console.WriteLine($" ___________\\___\\____||______________");
            Console.WriteLine($"");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" ***   TaskSchedulerConsole APP        **");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" *** @author: C.A Torino              ***");
            Console.WriteLine($" *** @initial_date: 18 September 2021 ***");
            Console.WriteLine($" *** @version: {Assembly.GetExecutingAssembly().GetName().Version}                ***");
            Console.WriteLine($" ****************************************");
            //Console.ReadKey();
        }
    }
}
