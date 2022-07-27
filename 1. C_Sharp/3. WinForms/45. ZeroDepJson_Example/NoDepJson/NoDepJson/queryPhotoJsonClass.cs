using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace NoDepJson
{
    internal class queryPhotoJsonClass
    {
        [DataContract]
        public class Rootobject
        {
            [DataMember]
            public int result { get; set; }
            [DataMember]
            public Pagination pagination { get; set; }
            [DataMember]
            public Info[] infos { get; set; }
        }
        [DataContract]
        public class Pagination
        {
            [DataMember]
            public bool hasPreviousPage { get; set; }
            [DataMember]
            public int totalRecords { get; set; }
            [DataMember]
            public int previousPage { get; set; }
            [DataMember]
            public bool directQuery { get; set; }
            [DataMember]
            public int nextPage { get; set; }
            [DataMember]
            public int currentPage { get; set; }
            [DataMember]
            public int endRecord { get; set; }
            [DataMember]
            public int pageRecords { get; set; }
            [DataMember]
            public int totalPages { get; set; }
            [DataMember]
            public int startRecord { get; set; }
            [DataMember]
            public bool hasNextPage { get; set; }
            [DataMember]
            public object sortParams { get; set; }
            [DataMember]
            public string primaryKey { get; set; }
        }
        [DataContract]
        public class Info
        {
            [DataMember]
            public object id { get; set; }
            [DataMember]
            public object fileName { get; set; }
            [DataMember]
            public int channel { get; set; }
            [DataMember]
            public string position { get; set; }
            [DataMember]
            public int mediaType { get; set; }
            [DataMember]
            public string devIdno { get; set; }
            [DataMember]
            public string vehiIdno { get; set; }
            [DataMember]
            public string remark { get; set; }
            [DataMember]
            public long updateTime { get; set; }
            [DataMember]
            public string label { get; set; }
            [DataMember]
            public object abbr { get; set; }
            [DataMember]
            public int fileType { get; set; }
            [DataMember]
            public int svrId { get; set; }
            [DataMember]
            public int alarmType { get; set; }
            [DataMember]
            public object videoFile { get; set; }
            [DataMember]
            public object violation { get; set; }
            [DataMember]
            public string gpsstatus { get; set; }
            [DataMember]
            public long fileTime { get; set; }
            [DataMember]
            public int fileTimeI { get; set; }
            [DataMember]
            public int fileLocation { get; set; }
            [DataMember]
            public object encode { get; set; }
            [DataMember]
            public int sourceID { get; set; }
            [DataMember]
            public object fileUrl { get; set; }
            [DataMember]
            public int weiDu { get; set; }
            [DataMember]
            public int jingDu { get; set; }
            [DataMember]
            public string filePath { get; set; }
            [DataMember]
            public int fileOffset { get; set; }
            [DataMember]
            public int fileSize { get; set; }
            [DataMember]
            public string downloadUrl { get; set; }
            [DataMember]
            public int alarmParam { get; set; }
            [DataMember]
            public int vehiId { get; set; }
        }

    }
}
