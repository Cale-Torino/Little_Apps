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
    public partial class ButtonsForm : Form
    {
        private readonly string _var;
        public ButtonsForm(string var)
        {
            _var = var;
            InitializeComponent();
        }

        private void ButtonsForm_Load(object sender, EventArgs e)
        {
            StripLabel.Text = _var;
        }


        private Button? lastButton = null;

        private void Chgcolor(Button current) 
        {

            if (lastButton != null)
            {
                lastButton.BackColor = SystemColors.Control;
            }

            lastButton = current;
            current.BackColor = Color.GreenYellow;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Chgcolor((Button)sender);
            ButtonsUC uc = new()
            {
                Dock = DockStyle.Fill
            };
            panelCon.Controls.Add(uc);
            panelCon.Controls["ButtonsUC"].BringToFront();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Chgcolor((Button)sender);
            ButtonsUC2 uc = new()
            {
                Dock = DockStyle.Fill
            };
            panelCon.Controls.Add(uc);
            panelCon.Controls["ButtonsUC2"].BringToFront();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Chgcolor((Button)sender);
            ButtonsUC3 uc = new()
            {
                Dock = DockStyle.Fill
            };
            panelCon.Controls.Add(uc);
            panelCon.Controls["ButtonsUC3"].BringToFront();
        }
    }
}
