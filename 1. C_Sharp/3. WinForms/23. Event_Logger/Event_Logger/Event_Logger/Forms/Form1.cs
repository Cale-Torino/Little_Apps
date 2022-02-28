using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Event_Logger.LoggerClass;

namespace Event_Logger
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_HelpButtonClicked(object sender, CancelEventArgs e)
        {
            //help button clicked
            Logger.WriteLine(" ***help button clicked*** ");
            Form2 f2 = new Form2();
            f2.ShowDialog();
            label1.Text = "help button clicked";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //delete log file
            try
            {
                Logger.DeleteLog();
                MessageBox.Show("Log file has been deleted.", "Delete Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Delete Failure", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            label1.Text = "delete log file";
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {
            //groupBox1 Enter changed
            Logger.WriteLine(" ***groupBox1 Enter  changed*** ");
            label1.Text = "groupBox1 Enter changed";
        }

        private void groupBox1_Leave(object sender, EventArgs e)
        {
            //groupBox1 Leave changed
            Logger.WriteLine(" ***groupBox1 Leave  changed*** ");
            label1.Text = "groupBox1 Leave changed";
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {
            //groupBox2 Enter changed
            Logger.WriteLine(" ***groupBox2 Enter  changed*** ");
            label1.Text = "groupBox2 Enter changed";
        }

        private void groupBox2_Leave(object sender, EventArgs e)
        {
            //groupBox2 Leave changed
            Logger.WriteLine(" ***groupBox2 Leave  changed*** ");
            label1.Text = "groupBox2 Leave changed";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //button 1 clicked
            Logger.WriteLine(" ***button 1 clicked*** ");
            label1.Text = "button 1 clicked";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //button 2 clicked
            Logger.WriteLine(" ***button 2 clicked*** ");
            label1.Text = "button 2 clicked";
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            //checkbox 1 changed
            Logger.WriteLine(" ***checkbox 1 changed*** ");
            label1.Text = "checkbox 1 changed";
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //comboBox1 SelectedIndexChanged  changed
            Logger.WriteLine(" ***comboBox1 SelectedIndexChanged  changed*** ");
            label1.Text = "comboBox1 SelectedIndexChanged  changed";
        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {
            //domainUpDown1 SelectedItemChanged  changed
            Logger.WriteLine(" ***domainUpDown1 SelectedItemChanged  changed*** ");
            label1.Text = "domainUpDown1 SelectedItemChanged  changed";
        }

        private void label2_Click(object sender, EventArgs e)
        {
            //label2 Click  changed
            Logger.WriteLine(" ***label2 Click  changed*** ");
            label1.Text = "label2 Click  changed";
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            //linkLabel1 LinkClicked  changed
            Logger.WriteLine(" ***linkLabel1 LinkClicked  changed*** ");
            label1.Text = "linkLabel1 LinkClicked  changed";
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            //radioButton1 CheckedChanged  changed
            Logger.WriteLine(" ***radioButton1 CheckedChanged  changed*** ");
            label1.Text = "radioButton1 CheckedChanged  changed";
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
            //maskedTextBox1 MaskInputRejected  changed
            Logger.WriteLine(" ***maskedTextBox1 MaskInputRejected  changed*** ");
            label1.Text = "maskedTextBox1 MaskInputRejected  changed";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //textBox1 TextChanged  changed
            Logger.WriteLine(" ***textBox1 TextChanged  changed*** ");
            label1.Text = "textBox1 TextChanged  changed";
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            //pictureBox1 Click  changed
            Logger.WriteLine(" ***pictureBox1 Click  changed*** ");
            label1.Text = "pictureBox1 Click  changed";
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            //trackBar1 Scroll changed
            Logger.WriteLine(" ***trackBar1 Scroll  changed*** ");
            label1.Text = "trackBar1 Scroll changed";
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            //numericUpDown1 ValueChanged changed
            Logger.WriteLine(" ***numericUpDown1 ValueChanged  changed*** ");
            label1.Text = "numericUpDown1 ValueChanged changed";
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {
            //progressBar1 Click changed
            Logger.WriteLine(" ***progressBar1 Click  changed*** ");
            label1.Text = "progressBar1 Click changed";
        }

        private void tabControl1_Enter(object sender, EventArgs e)
        {
            //tabControl1 Enter clicked
            Logger.WriteLine(" ***tabControl1 Enter clicked*** ");
            label1.Text = "tabControl1 Enter clicked";
        }

        private void tabControl1_Leave(object sender, EventArgs e)
        {
            //tabControl1 Leave clicked
            Logger.WriteLine(" ***tabControl1 Leave clicked*** ");
            label1.Text = "tabControl1 Leave clicked";
        }

        private void tabPage1_Enter(object sender, EventArgs e)
        {
            //tabPage1 Enter clicked
            Logger.WriteLine(" ***tabPage1 Enter clicked*** ");
            label1.Text = "tabPage1 Enter clicked";
        }

        private void tabPage1_Leave(object sender, EventArgs e)
        {
            //tabPage1 Leave clicked
            Logger.WriteLine(" ***tabPage1 Leave clicked*** ");
            label1.Text = "tabPage1 Leave clicked";
        }

        private void tabPage2_Enter(object sender, EventArgs e)
        {
            //tabPage2 Enter clicked
            Logger.WriteLine(" ***tabPage2 Enter clicked*** ");
            label1.Text = "tabPage2 Enter clicked";
        }

        private void tabPage2_Leave(object sender, EventArgs e)
        {
            //tabPage2 Leave clicked
            Logger.WriteLine(" ***tabPage2 Leave clicked*** ");
            label1.Text = "tabPage2 Leave clicked";
        }

        private void panel2_Click(object sender, EventArgs e)
        {
            //panel2 Click changed
            Logger.WriteLine(" ***panel2 Click changed*** ");
            label1.Text = "panel2 Click changed";
        }
        private void CreateFolder()
        {
            try
            {
                //CreatFolder
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + "\\Logs");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //load
            CreateFolder();
            label1.Text = "Ready";
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            //button1_MouseEnter changed
            Logger.WriteLine(" ***button1_MouseEnter changed*** ");
            label1.Text = "button1_MouseEnter changed";
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            //button1_MouseLeave changed
            Logger.WriteLine(" ***button1_MouseLeave changed*** ");
            label1.Text = "button1_MouseLeave changed";
        }

        private void button2_MouseEnter(object sender, EventArgs e)
        {
            //button2_MouseEnter changed
            Logger.WriteLine(" ***button2_MouseEnter changed*** ");
            label1.Text = "button2_MouseEnter changed";
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            //button2_MouseLeave changed
            Logger.WriteLine(" ***button2_MouseLeave changed*** ");
            label1.Text = "button2_MouseLeave changed";
        }

        private void checkBox1_MouseEnter(object sender, EventArgs e)
        {
            //checkBox1_MouseEnter changed
            Logger.WriteLine(" ***checkBox1_MouseEnter changed*** ");
            label1.Text = "checkBox1_MouseEnter changed";
        }

        private void checkBox1_MouseLeave(object sender, EventArgs e)
        {
            //checkBox1_MouseLeave changed
            Logger.WriteLine(" ***checkBox1_MouseLeave changed*** ");
            label1.Text = "checkBox1_MouseLeave changed";
        }

        private void comboBox1_MouseEnter(object sender, EventArgs e)
        {
            //comboBox1_MouseEnter changed
            Logger.WriteLine(" ***comboBox1_MouseEnter changed*** ");
            label1.Text = "comboBox1_MouseEnter changed";
        }

        private void comboBox1_MouseLeave(object sender, EventArgs e)
        {
            //comboBox1_MouseLeave changed
            Logger.WriteLine(" ***comboBox1_MouseLeave changed*** ");
            label1.Text = "comboBox1_MouseLeave changed";
        }

        private void label2_MouseEnter(object sender, EventArgs e)
        {
            //label2_MouseEnter changed
            Logger.WriteLine(" ***label2_MouseEnter changed*** ");
            label1.Text = "label2_MouseEnter changed";
        }

        private void label2_MouseLeave(object sender, EventArgs e)
        {
            //label2_MouseLeave changed
            Logger.WriteLine(" ***label2_MouseLeave changed*** ");
            label1.Text = "label2_MouseLeave changed";
        }

        private void linkLabel1_MouseEnter(object sender, EventArgs e)
        {
            //panel2 Click changed
            Logger.WriteLine(" ***linkLabel1_MouseEnter changed*** ");
            label1.Text = "linkLabel1_MouseEnter changed";
        }

        private void linkLabel1_MouseLeave(object sender, EventArgs e)
        {
            //linkLabel1_MouseLeave changed
            Logger.WriteLine(" ***linkLabel1_MouseLeave changed*** ");
            label1.Text = "linkLabel1_MouseLeave changed";
        }

        private void radioButton1_MouseEnter(object sender, EventArgs e)
        {
            //radioButton1_MouseEnter changed
            Logger.WriteLine(" ***radioButton1_MouseEnter changed*** ");
            label1.Text = "radioButton1_MouseEnter changed";
        }

        private void radioButton1_MouseLeave(object sender, EventArgs e)
        {
            //radioButton1_MouseLeave changed
            Logger.WriteLine(" ***radioButton1_MouseLeave changed*** ");
            label1.Text = "radioButton1_MouseLeave changed";
        }

        private void maskedTextBox1_MouseEnter(object sender, EventArgs e)
        {
            //maskedTextBox1_MouseEnter changed
            Logger.WriteLine(" ***maskedTextBox1_MouseEnter changed*** ");
            label1.Text = "maskedTextBox1_MouseEnter changed";
        }

        private void maskedTextBox1_MouseLeave(object sender, EventArgs e)
        {
            //maskedTextBox1_MouseLeave changed
            Logger.WriteLine(" ***maskedTextBox1_MouseLeave changed*** ");
            label1.Text = "maskedTextBox1_MouseLeave changed";
        }

        private void textBox1_MouseEnter(object sender, EventArgs e)
        {
            //textBox1_MouseEnter changed
            Logger.WriteLine(" ***textBox1_MouseEnter changed*** ");
            label1.Text = "textBox1_MouseEnter changed";
        }

        private void textBox1_MouseLeave(object sender, EventArgs e)
        {
            //textBox1_MouseLeave changed
            Logger.WriteLine(" ***textBox1_MouseLeave changed*** ");
            label1.Text = "textBox1_MouseLeave changed";
        }

        private void pictureBox1_MouseEnter(object sender, EventArgs e)
        {
            //pictureBox1_MouseEnter changed
            Logger.WriteLine(" ***pictureBox1_MouseEnter changed*** ");
            label1.Text = "pictureBox1_MouseEnter changed";
        }

        private void pictureBox1_MouseLeave(object sender, EventArgs e)
        {
            //pictureBox1_MouseLeave changed
            Logger.WriteLine(" ***pictureBox1_MouseLeave changed*** ");
            label1.Text = "pictureBox1_MouseLeave changed";
        }

        private void trackBar1_MouseEnter(object sender, EventArgs e)
        {
            //trackBar1_MouseEnter changed
            Logger.WriteLine(" ***trackBar1_MouseEnter changed*** ");
            label1.Text = "trackBar1_MouseEnter changed";
        }

        private void trackBar1_MouseLeave(object sender, EventArgs e)
        {
            //trackBar1_MouseLeave changed
            Logger.WriteLine(" ***trackBar1_MouseLeave changed*** ");
            label1.Text = "trackBar1_MouseLeave changed";
        }

        private void progressBar1_MouseEnter(object sender, EventArgs e)
        {
            //progressBar1_MouseEnter changed
            Logger.WriteLine(" ***progressBar1_MouseEnter changed*** ");
            label1.Text = "progressBar1_MouseEnter changed";
        }

        private void progressBar1_MouseLeave(object sender, EventArgs e)
        {
            //progressBar1_MouseLeave changed
            Logger.WriteLine(" ***progressBar1_MouseLeave changed*** ");
            label1.Text = "progressBar1_MouseLeave changed";
        }

        private void button3_MouseEnter(object sender, EventArgs e)
        {
            //button3_MouseEnter changed
            Logger.WriteLine(" ***button3_MouseEnter changed*** ");
            label1.Text = "button3_MouseEnter changed";
        }

        private void button3_MouseLeave(object sender, EventArgs e)
        {
            //button3_MouseLeave changed
            Logger.WriteLine(" ***button3_MouseLeave changed*** ");
            label1.Text = "button3_MouseLeave changed";
        }
    }
}
