using ProtoBuf;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Protobufexample
{
    public partial class MainForm : Form
    {
        static byte[] PersonBytes;
        public MainForm()
        {
            InitializeComponent();

            using (var memoryStream = new MemoryStream())
            {
                Serializer.Serialize(memoryStream, person);
                PersonBytes = memoryStream.ToArray();
            }
        }

        private void InitalizeLog()
        {
            Debug.Listeners.Add(TraceClass.GetTraceListenerh(TraceClass.GetLogPath()));
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            InitalizeLog();
            TraceClass.LogWrite("This is a log trace :) ", 0);//info
            TraceClass.LogWrite("This is a log trace :) ", 1);//warning
            TraceClass.LogWrite("This is a log trace :) ", 2);//error
            TraceClass.LogWrite("This is a log trace :) ", 3);//debug
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (var frm = new AboutForm("testing"))
            {
                frm.ShowDialog();
            }
        }
        static PersonClass person = new PersonClass
        {
            FirstName = "Wade",
            LastName = "G",
            Emails = new List<string>
            {
                "wade.g@gmail.com",
                "wade@business.com"
            }
        };
        public byte[] SerializeProtobuf()
        {
            Stopwatch sW = new Stopwatch();
            sW.Start();
            using (var memoryStream = new MemoryStream())
            {
                Serializer.Serialize(memoryStream, person);
                byte[] b = memoryStream.ToArray();
                sW.Stop();
                long ns = sW.ElapsedTicks * 1000000000 / Stopwatch.Frequency;
                long ms = sW.ElapsedMilliseconds;
                LogWindow("SerializeProtobuf Time> ", $"{ms} ms; {ns} ns;");
                return b;
            }
        }

        public PersonClass DeserializeProtobuf()
        {
            Stopwatch sW = new Stopwatch();
            sW.Start();
            using (var memoryStream = new MemoryStream(PersonBytes))
            {
                PersonClass Pc = Serializer.Deserialize<PersonClass>(memoryStream);
                sW.Stop();
                long ns = sW.ElapsedTicks * 1000000000 / Stopwatch.Frequency;
                long ms = sW.ElapsedMilliseconds;
                LogWindow("DeserializeProtobuf Time> ", $"{ms} ms; {ns} ns;");
                return Pc;
            }
        }

        private void Startbutton_Click(object sender, EventArgs e)
        {
            byte[] SP = SerializeProtobuf();
            PersonClass PC = DeserializeProtobuf();
            
            LogsrichTextBox.AppendText($"Data: {Encoding.UTF8.GetString(SP)}{Environment.NewLine}");
            LogsrichTextBox.AppendText($"Data: {PC.FirstName}; {PC.LastName}; {PC.Emails[0]}; {PC.Emails[1]}{Environment.NewLine}");
            LogsrichTextBox.ScrollToCaret();
        }

        void LogWindow(string description, string result)
        {
            LogsrichTextBox.AppendText($"[{DateTime.Now}] : {description}{result}{Environment.NewLine}");
        }

    }
}
