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
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void TreeViewbutton_Click(object sender, EventArgs e)
        {
            using TreeViewUserControlForm f = new("Tree");
            f.ShowDialog();
        }

        private void ListViewbutton_Click(object sender, EventArgs e)
        {
            using ListViewUserControlForm f = new("List");
            f.ShowDialog();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void Buttonsbutton_Click(object sender, EventArgs e)
        {
            using ButtonsForm f = new("Buttons");
            f.ShowDialog();
        }
    }
}
