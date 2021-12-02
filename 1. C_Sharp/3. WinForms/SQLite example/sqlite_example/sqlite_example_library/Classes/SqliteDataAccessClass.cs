using Dapper;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sqlite_example_library
{
    public class SqliteDataAccessClass
    {
        //LOAD PEOPLE
        public static List<PersonClass> LoadPeople()
        {
            using (IDbConnection cnn = new SQLiteConnection(LoadConnectionString()))
            {
                var output = cnn.Query<PersonClass>("select * from person", new DynamicParameters());
                return output.ToList();
            }
        }

        //SAVE PEOPLE
        public static void SavePerson(PersonClass person)
        {
            using (IDbConnection cnn = new SQLiteConnection(LoadConnectionString()))
            {
                cnn.Execute("insert into person (first_name, last_name) values (@first_name, @last_name)", person);
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
