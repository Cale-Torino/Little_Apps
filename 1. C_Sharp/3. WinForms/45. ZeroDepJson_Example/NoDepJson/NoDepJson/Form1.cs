using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NoDepJson
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //string Loginobject = "{\"access_token\": \"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9\",\"token_type\": \"bearer\",\"expires_in\": 1658445625,\"refresh_token\": \"cd26210d7dd1cf5646c6-5a151d987ee7b5c5f6a931b2e4d07da9bdec6fad3318b1cb-793ba7b3da\",\"scope\": \"authorization,my_scope\"}";
            //string Errorobject = "{\"error\": \"server_error\",\"error_description\": \"Invalid refresh token\"}";
            //Ser(Loginobject);
        }

        private void JsonSerializer()
        {

            using (StreamReader result = new StreamReader("queryPhotoJsonClass.json"))
            {
                string json = result.ReadToEnd();
                queryPhotoJsonClass.Rootobject dr = JsonClass.JSONSerializer<queryPhotoJsonClass.Rootobject>.DeSerialize(json);

                int r = dr.result;
                richTextBox3.AppendText($"result = {r}{Environment.NewLine}");
                queryPhotoJsonClass.Info[] infos = dr.infos;
                foreach (var item in infos)
                {
                    richTextBox3.AppendText($"devIdno = {item.devIdno}, position = {item.fileSize}{Environment.NewLine}");
                }
                queryPhotoJsonClass.Pagination pagination = dr.pagination;
                richTextBox3.AppendText($"nextPage = {pagination.nextPage}, currentPage = {pagination.currentPage}{Environment.NewLine}");
            }
        }

        private void Ser(string json)
        {
            //https://stackoverflow.com/questions/9573119/how-to-parse-json-without-json-net-library
            //https://github.com/smourier/ZeroDepJson

            //string json = "[{\"Index\":1},{\"Index\":2},{\"Index\":3},{\"Index\":4},{\"Index\":5},{\"Index\":6},{\"Index\":7},{\"Index\":8},{\"Index\":9}]";
            //var json = Json.Serialize(input);
            //richTextBox1.AppendText(json);
            List<JsonListClass.Loginobject> list = Json.Deserialize<List<JsonListClass.Loginobject>>(json);
            foreach (var item in list)
            {
/*                if (string.IsNullOrEmpty(item.access_token))
                {
                    richTextBox2.AppendText($"Bloody{item.access_token}{Environment.NewLine}");
                }*/
            }
            //string d = Json.WriteFormatted(list2);
            string d = Json.WriteFormatted(json);
            richTextBox3.AppendText(d);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            notifyIcon.Visible = true;
            notifyIcon.Icon = SystemIcons.Application;
            notifyIcon.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon.BalloonTipText = "I am a NotifyIcon Balloon";
            notifyIcon.BalloonTipTitle = "Welcome Message";
            notifyIcon.ShowBalloonTip(1000);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            JsonSerializer();
        }
    }
}
