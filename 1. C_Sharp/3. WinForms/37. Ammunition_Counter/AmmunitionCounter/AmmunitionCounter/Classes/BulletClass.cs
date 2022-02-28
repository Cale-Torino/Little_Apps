using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AmmunitionCounter
{
    public class BulletClass
    {
        public int id { get; set; }
        public string caliber { get; set; }
        public string brand { get; set; }
        public string grain { get; set; }
        public string shot { get; set; }
        public string all_data
        {
            get
            {
                return $"{ id }{ caliber }{ brand }{ grain }{ shot }";
            }
        }
    }
}
