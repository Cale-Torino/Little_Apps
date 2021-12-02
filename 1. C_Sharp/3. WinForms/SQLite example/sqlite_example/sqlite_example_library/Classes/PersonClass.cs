using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sqlite_example_library
{
    public class PersonClass
    {
        public int id { get; set; }
        public string first_name { get; set; }
        public string last_name { get; set; }

        public string full_name
        {
            get
            {
                return $"{ first_name } { last_name }";
            }
        }
    }
}
