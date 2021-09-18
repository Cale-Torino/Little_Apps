using System;
using System.IO;
using System.Reflection;

namespace LoginAlert
{
    class AboutClass
    {
        public void Author_Details()
        {
            Console.WriteLine($"[{DateTime.Now}] => {Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location)}");
            Console.WriteLine($"");
            Console.WriteLine($"             _ _ _ _ ||_LoginAlert_ _ _ _ _ _ _");
            Console.WriteLine($"             \\  _  _ ||  _  _ _ ___");
            Console.WriteLine($"             / /__/ \\|| |_/");
            Console.WriteLine($"            / __   / || -  _ ___");
            Console.WriteLine($"           / /  / /  ||/ /");
            Console.WriteLine($"   _ _ _ _/ /  /  \\_/||  \\_ ______");
            Console.WriteLine($" ___________\\___\\____||______________");
            Console.WriteLine($"");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" ***   LoginAlert APPLICATION         ***");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" ****************************************");
            Console.WriteLine($" *** @author: C.A Torino              ***");
            Console.WriteLine($" *** @initial_date: 15 September 2021 ***");
            Console.WriteLine($" *** @version: {Assembly.GetExecutingAssembly().GetName().Version}                ***");
            Console.WriteLine($" ****************************************");
            //Console.ReadKey();
        }
    }
}
