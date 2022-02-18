using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Maths_Testing_Application
{
    internal class VarsClass
    {
        private static string _MachineName;
        public static string MachineName
        {
            get
            {
                return _MachineName;
            }
            set
            {
                _MachineName = value;
            }
        }
        private static string _Message;
        public static string Message
        {
            get
            {
                return _Message;
            }
            set
            {
                _Message = value;
            }
        }
        private static string _UserName;
        public static string UserName
        {
            get
            {
                return _UserName;
            }
            set
            {
                _UserName = value;
            }
        }
        private static string _DateTime;
        public static string DateTime
        {
            get
            {
                return _DateTime;
            }
            set
            {
                _DateTime = value;
            }
        }
      





    }
}
