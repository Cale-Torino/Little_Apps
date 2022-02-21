using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MergingAssemblies
{
    public partial class MainForm : Form
    {
        //https://github.com/ravibpatel/ILRepack.Lib.MSBuild.Task

        //https://www.meziantou.net/merging-assemblies-using-ilrepack.htm

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "Ready";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string C1 = ClassLibrary1.Class1.Hello();
            string C2 = ClassLibrary2.Class1.Hello();
            toolStripStatusLabel1.Text = $"[{DateTime.Now}] : {C1} | {C2}";
        }
    }
}
