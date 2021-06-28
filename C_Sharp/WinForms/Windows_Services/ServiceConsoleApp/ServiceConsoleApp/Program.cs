using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Topshelf;

namespace ServiceConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var exitCode = HostFactory.Run(x => 
            {
                x.Service<ServiceClass>(s => 
                {
                    s.ConstructUsing(ServiceClass => new ServiceClass());
                    s.WhenStarted(ServiceClass => ServiceClass.Start());
                    s.WhenStopped(ServiceClass => ServiceClass.Stop());
                });
                x.RunAsLocalSystem();

                x.SetServiceName("ServiceConsoleAppService");
                x.SetDisplayName("Service Console App Service");
                x.SetDescription("This is a sample application used to see how services work");

            });

            int exitCodeValue = (int)Convert.ChangeType(exitCode, exitCode.GetTypeCode());
            Environment.ExitCode = exitCodeValue;
        }
    }
}
