using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TraceLog
{
    public partial class Form2 : Form
    {
        private readonly string _testing;
        public Form2(string testing)
        {
            _testing = testing;
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            label1.Text = _testing;
        }
        int i = 0;
        private void Logbutton_Click(object sender, EventArgs e)
        {
            i++;
            TraceClass.LogWrite($"{i} log trace Form 2 :) ", 0);
        }
    }
}
