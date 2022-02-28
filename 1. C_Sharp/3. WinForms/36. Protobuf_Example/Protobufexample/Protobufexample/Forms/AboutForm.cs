using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Protobufexample
{
    public partial class AboutForm : Form
    {
        private readonly string _testing;
        public AboutForm(string testing)
        {
            _testing = testing;
            InitializeComponent();
        }

        private void AboutForm_Load(object sender, EventArgs e)
        {
            label1.Text = _testing;
        }
    }
}
