using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HTTPSERVER
{
    //https://www.newtonsoft.com/json/help/html/SerializeObject.htm
    public class RequestClass
    {
        public string Tag { get; set; }
        public string Email { get; set; }
        public bool Active { get; set; }
        public DateTime CreatedDate { get; set; }
        public IList<string> Roles { get; set; }
    }
}
