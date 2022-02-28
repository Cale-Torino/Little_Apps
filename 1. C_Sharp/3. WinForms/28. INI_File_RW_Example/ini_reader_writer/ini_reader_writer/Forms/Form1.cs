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

namespace ini_reader_writer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string A = Application.StartupPath + "\\Logs\\ini_reader_writer_" + DateTime.Now.ToString("yyyy-dd-M") + ".ini";
                IniReadWriteClass.INIFile ini = new IniReadWriteClass.INIFile(A);
                string _Section = textBox1.Text;
                string _Key = textBox2.Text;
                string _Value = textBox3.Text;
                ini.IniWriteValue(_Section, _Key, _Value);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "IniWriteValue Error", MessageBoxButtons.OK,MessageBoxIcon.Error);
                return;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                //CreatFolder
                textBox1.Text = "testing_section";
                textBox2.Text = "this_is_the_key";
                textBox3.Text = "this_is_the_value";
                string path = Application.StartupPath;
                Directory.CreateDirectory(path + "\\Logs");
                Directory.CreateDirectory(path + "\\Temp");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Create Folder Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string A = Application.StartupPath + "\\Logs\\ini_reader_writer_" + DateTime.Now.ToString("yyyy-dd-M") + ".ini";
                IniReadWriteClass.INIFile ini = new IniReadWriteClass.INIFile(A);
                string _Section = textBox1.Text;
                string _Key = textBox2.Text;
                string read = ini.IniReadValue(_Section, _Key);
                MessageBox.Show(read, "Ini Read Value");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "IniReadValue Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.ShowDialog();
        }
    }
}
