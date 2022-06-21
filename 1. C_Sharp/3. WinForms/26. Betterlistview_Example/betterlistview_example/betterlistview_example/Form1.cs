using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace betterlistview_example
{
    //http://objectlistview.sourceforge.net/cs/index.html
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //HeaderClass.colorListViewHeader(ref listView1, Color.Black, Color.DarkOrange);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            foreach (object item in listView1.Items)
            {
                sb.Append(item.ToString());
                sb.Append(" ");
            }
            MessageBox.Show(sb.ToString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ListViewItem item = new ListViewItem(new[] { "Mike Gold", "Praveen Kumar", "Raj Beniwal", "Raj Beniwal" });
            listView1.Items.Add(item);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ListViewItem item1 = new ListViewItem("Something");
            item1.SubItems.Add("SubItem1a");
            item1.SubItems.Add("SubItem1b");
            item1.SubItems.Add("SubItem1c");

            ListViewItem item2 = new ListViewItem("Something2");
            item2.SubItems.Add("SubItem2a");
            item2.SubItems.Add("SubItem2b");
            item2.SubItems.Add("SubItem2c");

            ListViewItem item3 = new ListViewItem("Something3");
            item3.SubItems.Add("SubItem3a");
            item3.SubItems.Add("SubItem3b");
            item3.SubItems.Add("SubItem3c");

            listView1.Items.AddRange(new ListViewItem[] { item1, item2, item3 });
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //https://stackoverflow.com/questions/17381725/c-sharp-listview-item-image


            //il.ImageSize = new Size(32, 32);
            int count = 0;
            listView1.SmallImageList = imageList1;
            List<string> names = new List<string>() { "1", "2", "3", "4" };

            foreach (string s in names)
            {
                ListViewItem lst = new ListViewItem(new[] { "Mike Gold", "Praveen Kumar", "Raj Beniwal", "Raj Beniwal" });
                lst.Text = s;
                lst.ImageIndex = count++;
                listView1.Items.Add(lst);
            }


        }

        private void button6_Click(object sender, EventArgs e)
        {
            //http://ip-api.com/json/102.249.0.85
            //http://free.ipwhois.io/json/102.249.0.85
            listView1.SmallImageList = imageList1;
            int length = 5;
            int count = 0;
            for (int i = 0; i < length; i++)
            {             
                ListViewItem lst = new ListViewItem(new[] { "Mike Gold", "Praveen Kumar", "Raj Beniwal", "Raj Beniwal" });
                lst.Text = " - Country";
                lst.ImageIndex = i;
                if (count++ % 2 == 0)
                { lst.BackColor = Color.DarkSlateGray; }
                listView1.Items.Add(lst);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listView1.Columns.Add("", 100, HorizontalAlignment.Left);

            DarkTitleBarClass.UseImmersiveDarkMode(Handle, true);
            DarkTitleBarClass.SetWindowTheme(listView1.Handle, "DarkMode_Explorer", null);
            listBox1.Items.AddRange(new object[] {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"});
            DarkTitleBarClass.SetWindowTheme(listBox1.Handle, "DarkMode_Explorer", null);
        }

        private void listView1_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e)
        {
            //var brush = new SolidBrush(Color.FromArgb(255, 25, 25, 25));
            e.Graphics.FillRectangle(Brushes.DimGray, e.Bounds);
            //e.Header.AutoResize(ColumnHeaderAutoResizeStyle.HeaderSize);
            //e.Header.Width.CompareTo(e.Bounds.Width);
            //e.Header.Width = 100;
            e.DrawText();
        }

        private void listView1_DrawItem(object sender, DrawListViewItemEventArgs e)
        {
            e.DrawDefault = true;
        }
    }
}
 