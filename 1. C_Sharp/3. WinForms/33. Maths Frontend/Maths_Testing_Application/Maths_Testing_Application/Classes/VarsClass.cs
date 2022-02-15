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
        private static string _Command;
        public static string Command
        {
            get
            {
                return _Command;
            }
            set
            {
                _Command = value;
            }
        }
        private static TcpListener _listener;
        public static TcpListener listener
        {
            get
            {
                return _listener;
            }
            set
            {
                _listener = value;
            }
        }

        private static NetworkStream _nwStream;

        public static NetworkStream nwStream
        {
            get
            {
                return _nwStream;
            }
            set
            {
                _nwStream = value;
            }
        }
        private static Socket _client;

        public static Socket client
        {
            get
            {
                return _client;
            }
            set
            {
                _client = value;
            }
        }
        //private static TcpClient _client;

        //    public static TcpClient client
        //    {
        //        get
        //        {
        //            return _client;
        //        }
        //        set
        //        {
        //            _client = value;
        //        }
        //    }

        private static string _DevID;
        public static string DevID
        {
            get
            {
                return _DevID;
            }
            set
            {
                _DevID = value;
            }
        }

        private static int _noofclients;
        public static int noofclients
        {
            get
            {
                return _noofclients;
            }
            set
            {
                _noofclients = value;
            }
        }
        private static int _noofsockets;
        public static int noofsockets
        {
            get
            {
                return _noofsockets;
            }
            set
            {
                _noofsockets = value;
            }
        }
    }
}
