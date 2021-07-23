using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Formswithinfoms
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        private Form activeForm = null;
        private void openChildForm(Form childForm)
        {
            if (activeForm != null)
            {
                activeForm.Close();
            }
            activeForm = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            panel2.Controls.Add(childForm);
            panel2.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }
        Button lastButton = new Button();
        private void button1_Click(object sender, EventArgs e)
        {
            // Change the background color of the button that was clicked
            Button current = (Button)sender;
            current.BackColor = Color.FromArgb(50, 62, 63);

            // Revert the background color of the previously-colored button, if any
            if (lastButton != null)
            {
                lastButton.BackColor = Color.FromArgb(26, 32, 63);
            }
                

            // Update the previously-colored button
            lastButton = current;
            openChildForm(new Form1());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Change the background color of the button that was clicked
            Button current = (Button)sender;
            current.BackColor = Color.FromArgb(50, 62, 63);

            // Revert the background color of the previously-colored button, if any
            if (lastButton != null)
            {
                lastButton.BackColor = Color.FromArgb(26, 32, 63);
            }


            // Update the previously-colored button
            lastButton = current;
            openChildForm(new Form2());
        }
    }
}
