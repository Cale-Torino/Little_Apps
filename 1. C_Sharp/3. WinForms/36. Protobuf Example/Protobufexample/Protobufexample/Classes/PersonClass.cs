using ProtoBuf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Protobufexample
{
    [ProtoContract]
    public class PersonClass
    {
            [ProtoMember(1)]
            public string FirstName { get; set; }
            [ProtoMember(2)]
            public string LastName { get; set; }
            [ProtoMember(3)]
            public List<string> Emails { get; set; }
    }
}
