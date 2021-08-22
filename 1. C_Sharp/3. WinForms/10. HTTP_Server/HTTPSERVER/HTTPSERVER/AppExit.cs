using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace HTTPSERVER
{
    class AppExit
    {
        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public static void WaitFor(CancellationTokenSource cts, params Task[] tasks)
        {
            if (cts == null)
                throw new ArgumentNullException(nameof(cts));

            if (tasks == null)
                throw new ArgumentNullException(nameof(tasks));

            Task.Run(() =>
            {
                log.Info("------Press [Enter] to stop------");

                cancelTasks(cts);
            });

            waitTasks(tasks);
        }

        static void cancelTasks(CancellationTokenSource cts)
        {
            log.Info("Waiting for the tasks to complete...");
            cts.Cancel();
        }

        static void waitTasks(Task[] tasks)
        {
            try
            {
                foreach (var t in tasks) //enables exception handling
                    t.Wait();
            }
            catch (Exception ex)
            {
                writeError(ex);
            }
        }

        static void writeError(Exception ex)
        {
            if (ex == null)
                return;

            if (ex is AggregateException)
                ex = ex.InnerException;

            log.Error("Error: " + ex.Message);
        }
    }
}
