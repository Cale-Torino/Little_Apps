using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace ServiceConsoleApp
{
    class ServiceClass
    {
        private readonly Timer _timer;

        public ServiceClass()
        {
            _timer = new Timer(1000) { AutoReset = true };
            _timer.Elapsed += TimerElapsed;
        }

        private void TimerElapsed(object sender, ElapsedEventArgs e)
        {
            string[] lines = new string[] { DateTime.Now.ToString() };
            File.AppendAllLines(@"ServiceClass.log", lines);
        }

        public void Start()
        {
            _timer.Start();        
        }

        public void Stop()
        {
            _timer.Stop();
        }

    }
}
