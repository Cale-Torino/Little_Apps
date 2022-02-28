using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Maths_Testing_Application
{
    //https://www.newtonsoft.com/json/help/html/SerializeObject.htm
    internal class RequestClass
    {
        public string MachineName { get; set; }
        public string Message { get; set; }
        public string UserName { get; set; }
        public string DateTime { get; set; }
        public bool Active { get; set; }
        public DateTime CreatedDate { get; set; }
        public IList<string> Roles { get; set; }
    }
}
