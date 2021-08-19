using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TableListExample
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        int i = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            i++;
            string[] id = { i.ToString() };
            ListViewItem item = new ListViewItem(id, 0, Color.Black, Color.White, null);
            item.SubItems.Add("James", Color.Black, Color.White, null);
            item.SubItems.Add("Bond", Color.Black, Color.White, null);
            item.SubItems.Add("21 Jump Street", Color.Black, Color.White, null);
            listView1.Items.Add(item);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                listView1.Items.Remove(listView1.SelectedItems[0]);
            }
            else
            {
                MessageBox.Show("Please Select A Record", "No Record Selected", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int i = listView1.Items.Count;
            MessageBox.Show(i.ToString(),"Number Of Items",MessageBoxButtons.OK,MessageBoxIcon.Information);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
        }

        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                MenuStrip.Show(Cursor.Position);
                string a = listView1.SelectedItems[0].Text;
                string b = listView1.SelectedItems[0].SubItems[1].Text;
                string c = listView1.SelectedItems[0].SubItems[2].Text;
                string d = listView1.SelectedItems[0].SubItems[3].Text;
                Status.Text = $" {a} | {b} | {c} | {d} ";
                //listView1.SelectedItems[0].Selected;
                //listView1.Items.Remove(listView1.SelectedItems[0]);
                // && e.Node.Checked == false
            }
            else
            if (e.Button == MouseButtons.Left)
            {
                // && e.Node.Checked == false
                //ClientstreeView.SelectedNode = e.Node;
            }
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                listView1.Items.Remove(listView1.SelectedItems[0]);
            }
            else
            {
                MessageBox.Show("Please Select A Record", "No Record Selected", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
