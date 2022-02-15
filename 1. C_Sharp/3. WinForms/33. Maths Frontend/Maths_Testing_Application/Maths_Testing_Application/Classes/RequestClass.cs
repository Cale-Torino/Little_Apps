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
        public string Tag { get; set; }
        public string data1 { get; set; }
        public string data2 { get; set; }
        public string Email { get; set; }
        public bool Active { get; set; }
        public DateTime CreatedDate { get; set; }
        public IList<string> Roles { get; set; }
    }
}
