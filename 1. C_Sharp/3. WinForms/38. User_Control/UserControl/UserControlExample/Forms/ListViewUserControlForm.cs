using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UserControlExample
{
    public partial class ListViewUserControlForm : Form
    {
        private readonly string _var;

        public ListViewUserControlForm(string var)
        {
            _var = var;
            InitializeComponent();
        }

        private void ListViewUserControlForm_Load(object sender, EventArgs e)
        {
            //AddListItem();
            StripLabel.Text = _var;
        }

        private void AddListItem()
        {
            ListViewItem listitem1 = new()
            {
                Text = "Test1",
                Tag = "Test1"
            };
            ListViewItem listitem2 = new()
            {
                Text = "Test2",
                Tag = "Test2"
            };
            ListViewItem listitem3 = new()
            {
                Text = "Test3",
                Tag = "Test3"
            };
            listBox.Items.Add(listitem1);
            listBox.Items.Add(listitem2);
            listBox.Items.Add(listitem3);
        }

        private void listBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            StripLabel.Text = listBox.SelectedItem.ToString();
            switch (listBox.SelectedIndex)
            {
                case 0:
                    ListUC uc = new()
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc);
                    panelCon.Controls["ListUC"].BringToFront();
                    break;
                case 1:
                    ListUC2 uc2 = new()
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc2);
                    panelCon.Controls["ListUC2"].BringToFront();
                    break;
                case 2:
                    ListUC3 uc3 = new()
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc3);
                    panelCon.Controls["ListUC3"].BringToFront();
                    break;
                default:
                    break;
            }
        }
    }
}
