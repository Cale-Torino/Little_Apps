using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoDepJson
{
    internal class JsonListClass
    {
        public class Errorobject
        {
            public string error { get; set; } = "";
            public string error_description { get; set; } = "";
        }

        public class Loginobject
        {
            public string access_token { get; set; } = "";
            public string token_type { get; set; } = "";
            public int expires_in { get; set; } = 0;
            public string refresh_token { get; set; } = "";
            public string scope { get; set; } = "";
        }


        public class Rootobject
        {
            public int result { get; set; }
            public Pagination pagination { get; set; }
            public Info[] infos { get; set; }
        }

        public class Pagination
        {
            public bool hasPreviousPage { get; set; }
            public int totalRecords { get; set; }
            public int previousPage { get; set; }
            public bool directQuery { get; set; }
            public int nextPage { get; set; }
            public int currentPage { get; set; }
            public int endRecord { get; set; }
            public int pageRecords { get; set; }
            public int totalPages { get; set; }
            public int startRecord { get; set; }
            public bool hasNextPage { get; set; }
            public object sortParams { get; set; }
            public string primaryKey { get; set; }
        }

        public class Info
        {
            public object id { get; set; }
            public object fileName { get; set; }
            public int channel { get; set; }
            public string position { get; set; }
            public int mediaType { get; set; }
            public string devIdno { get; set; }
            public string vehiIdno { get; set; }
            public string remark { get; set; }
            public long updateTime { get; set; }
            public string label { get; set; }
            public object abbr { get; set; }
            public int fileType { get; set; }
            public int svrId { get; set; }
            public int alarmType { get; set; }
            public object videoFile { get; set; }
            public object violation { get; set; }
            public string gpsstatus { get; set; }
            public long fileTime { get; set; }
            public int fileTimeI { get; set; }
            public int fileLocation { get; set; }
            public object encode { get; set; }
            public int sourceID { get; set; }
            public object fileUrl { get; set; }
            public int weiDu { get; set; }
            public int jingDu { get; set; }
            public string filePath { get; set; }
            public int fileOffset { get; set; }
            public int fileSize { get; set; }
            public string downloadUrl { get; set; }
            public int alarmParam { get; set; }
            public int vehiId { get; set; }
        }


    }
}
