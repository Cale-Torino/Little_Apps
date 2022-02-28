using Dapper;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AmmunitionCounter
{
    public class SqliteDataAccessClass
    {
        //LOAD PEOPLE
        public static List<BulletClass> LoadBullets()
        {
            using (IDbConnection cnn = new SQLiteConnection(LoadConnectionString()))
            {
                var output = cnn.Query<BulletClass>("select * from bullets", new DynamicParameters());
                return output.ToList();
            }
        }

        //SAVE PEOPLE
        public static void SaveBullet(BulletClass bullet)
        {
            using (IDbConnection cnn = new SQLiteConnection(LoadConnectionString()))
            {
                cnn.Execute("insert into bullets (caliber, brand, grain, shot) values (@caliber, @brand, @grain, @shot)", bullet);
            }
        }
        //CONNECTION
        private static string LoadConnectionString(string id = "Default")
        {
            //gets connection string from the winforms app.config file
            return ConfigurationManager.ConnectionStrings[id].ConnectionString;
        }
    }
}
