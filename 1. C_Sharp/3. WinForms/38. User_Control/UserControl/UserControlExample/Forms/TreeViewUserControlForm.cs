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
    public partial class TreeViewUserControlForm : Form
    {
        private readonly string _var;
        public TreeViewUserControlForm(string var)
        {
            _var = var;
            InitializeComponent();
        }

        private void TreeViewUserControlForm_Load(object sender, EventArgs e)
        {
            //AddNode();

            StripLabel.Text = _var;
        }

        private void AddNode()
        {
            // start off by adding a base treeview node
            TreeNode mainNode = new()
            {
                Name = "Node1",
                Text = "Node1"
            };
            TreeNode mainNode2 = new()
            {
                Name = "Node2",
                Text = "Node2"
            };
            TreeNode mainNode3 = new()
            {
                Name = "Node3",
                Text = "Node3"
            };
            treeView.Nodes.Add(mainNode);
            treeView.Nodes.Add(mainNode2);
            treeView.Nodes.Add(mainNode3);
        }

        private void treeView_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {

        }

        private void treeView_AfterSelect(object sender, TreeViewEventArgs e)
        {
            StripLabel.Text = e.Node.Text;
            switch (e.Node.Index)
            {
                case 0:
                    TreeUC uc = new("Hello List")
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc);
                    panelCon.Controls["TreeUC"].BringToFront();
                    break;
                case 1:
                    TreeUC2 uc2 = new()
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc2);
                    panelCon.Controls["TreeUC2"].BringToFront();
                    break;
                case 2:
                    TreeUC3 uc3 = new()
                    {
                        Dock = DockStyle.Fill
                    };
                    panelCon.Controls.Add(uc3);
                    panelCon.Controls["TreeUC3"].BringToFront();
                    break;
                default:
                    break;
            }
        }
    }
}
