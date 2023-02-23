using EncryptStringSample;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.IO;
using System.Threading;
using System.Timers;
using MessagingToolkit.QRCode.Codec;
using MessagingToolkit.QRCode.Codec.Data;

namespace CrypterAIO
{
    public partial class Form1 : Form
    {
        public string _theme;
        public Form1()
        {
            InitializeComponent();
            menuStrip1.Renderer = new LavenderTheme.MyRenderer();
        }



        private void DrawOnTab(object sender, DrawItemEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen p = new Pen(Color.Blue);
            Font font = new Font("Arial", 10.0f);
            SolidBrush brush = new SolidBrush(Color.Red);
            SolidBrush brush1 = new SolidBrush(Color.Beige);
            //g.DrawRectangle(p, tabPag);
            //g.DrawString("tabPage1", font, brush, tabTextArea);
        }

        private void AboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.ShowDialog();
        }

        private void encryptBtn_Click_1(object sender, EventArgs e)
        {
            try
            {
                string password = encryptSecret.Text;
                string plaintext = encryptString.Text;
                string encryptedstring = StringCipher.Encrypt(plaintext, password);
                encryptOutput.Text = encryptedstring;

                DateTime _datetime = DateTime.Now;
                string _n = Environment.NewLine;
                richTextBox1.AppendText("[" + _datetime + "] ***Encrypt Button***" + _n + "[" +_datetime+"] Salt:"+ password + _n + "[" + _datetime + "] Message:" + plaintext + _n + "[" + _datetime + "] Encrypted:" + encryptedstring + _n + "______________________________" + _n);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "An error in the encrypting has occurred!");
            }
        }

        private void decryptBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string password = decryptSecret.Text;
                string encryptedstring = decryptString.Text;
                string decryptedstring = StringCipher.Decrypt(encryptedstring, password);
                decryptOutput.Text = decryptedstring;

                DateTime _datetime = DateTime.Now;
                string _n = Environment.NewLine;
                richTextBox1.AppendText("[" + _datetime + "] ***Decrypt Button***" + _n + "[" + _datetime + "] Salt:" + password + _n + "[" + _datetime + "] Encrypted:" + encryptedstring + _n + "[" + _datetime + "] Decrypted:" + decryptedstring + _n + "______________________________" + _n);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "An error in the decrypting has occurred!");
            }
        }

        private void qrInput_Click(object sender, EventArgs e)
        {
            if (qrInput.Text == "Enter Input Here...")
            {
                qrInput.Text = "";
                qrInput.ForeColor = Color.White;
            }
        }

        private void qrEncode_Click(object sender, EventArgs e)
        {
            string password = qrSecret.Text;
            string plaintext = qrInput.Text;
            string encryptedstring = StringCipher.Encrypt(plaintext, password);

            DateTime _datetime = DateTime.Now;
            string _n = Environment.NewLine;
            richTextBox1.AppendText("[" + _datetime + "] ***QREncode Button***" + _n + "[" + _datetime + "] Salt:" + password + _n + "[" + _datetime + "] Message:" + plaintext + _n + "[" + _datetime + "] Encrypted:" + encryptedstring + _n + "______________________________" + _n);

            using (SaveFileDialog sfd = new SaveFileDialog())
            {
                try
                {
                    sfd.Filter = @"JPEG files|*.jpg;*.jpeg;";
                    sfd.ValidateNames = true;
                    if (sfd.ShowDialog() == DialogResult.OK)
                    {
                        QRCodeEncoder encoder = new QRCodeEncoder();
                        encoder.QRCodeScale = 8;
                        Bitmap bmp = encoder.Encode(encryptedstring);
                        qrPicture.Image = bmp;
                        bmp.Save(sfd.FileName, ImageFormat.Jpeg);
                        qrPicture.Image = Image.FromFile(sfd.FileName);
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "An error in the encoding has occurred!");
                }
            }
        }

        private void qrDecode_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd1 = new OpenFileDialog())
            {
                try
                {
                    ofd1.Filter = @"JPEG files|*.jpg;*.jpeg;";
                    ofd1.ValidateNames = true;
                    ofd1.Multiselect = false;
                    if (ofd1.ShowDialog() == DialogResult.OK)
                    {
                        qrPicture.Image = Image.FromFile(ofd1.FileName);
                        QRCodeDecoder decoder = new QRCodeDecoder();

                        string password = qrSecret.Text;
                        string encryptedstring = decoder.Decode(new QRCodeBitmapImage(qrPicture.Image as Bitmap));
                        string decryptedstring = StringCipher.Decrypt(encryptedstring, password);
                        qrOutput.Text = decryptedstring;

                        DateTime _datetime = DateTime.Now;
                        string _n = Environment.NewLine;
                        richTextBox1.AppendText("[" + _datetime + "] ***QRDecode Button***" + _n + "[" + _datetime + "] Salt:" + password + _n + "[" + _datetime + "] Encrypted:" + encryptedstring + _n + "[" + _datetime + "] Decrypted:" + decryptedstring + _n + "______________________________" + _n);
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString(), "An error in the decoding has occurred!");
                }
            }
        }

        private void massString_Click(object sender, EventArgs e)
        {
            if (massString.Text == "Enter string here, lines seperate strings...")
            {
                massString.Text = "";
                massString.ForeColor = Color.White;
            }
        }

        private void massEncode_Click(object sender, EventArgs e)
        {
            using (StringReader reader = new StringReader(massString.Text))
            {
                string line;
                massOutput.Text = "";
                List<string> _List = new List<string>();                
                while ((line = reader.ReadLine()) != null)
                    {
                    try
                        {
                            string password = massSecret.Text;
                            string plaintext = line;
                            string encryptedstring = StringCipher.Encrypt(plaintext, password);
                            massOutput.Text = massOutput.Text + encryptedstring + Environment.NewLine;

                            _List.Add(password);
                            _List.Add(plaintext);
                            _List.Add(encryptedstring);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.ToString(), "An error in the encrypting has occurred!");
                    }
                    DateTime _datetime = DateTime.Now;
                    string _n = Environment.NewLine;
                    richTextBox1.AppendText("[" + _datetime + "] ***Mass Encode Button***" + _n);
                    foreach (var item in _List)
                    {
                        richTextBox1.AppendText("***Mass Encode =>" + item + _n);
                    }
                    richTextBox1.AppendText("______________________________" + _n);
                }
            }
        }

        private void massDeString_Click(object sender, EventArgs e)
        {
            if (massDeString.Text == "Enter string here, lines seperate strings...")
            {
                massDeString.Text = "";
                massDeString.ForeColor = Color.White;
            }
        }

        private void massDecode_Click(object sender, EventArgs e)
        {
            using (StringReader reader = new StringReader(massDeString.Text))
            {
                string line;
                massDeOutput.Text = "";
                while ((line = reader.ReadLine()) != null)
                {
                    try
                    {
                        string password = massDeSecret.Text;
                        string encryptedstring = line;
                        string decryptedstring = StringCipher.Decrypt(encryptedstring, password);
                        massDeOutput.Text = massDeOutput.Text + decryptedstring + Environment.NewLine;

                        DateTime _datetime = DateTime.Now;
                        string _n = Environment.NewLine;
                        richTextBox1.AppendText("[" + _datetime + "] ***Mass Decode Button***" + _n + "[" + _datetime + "] Salt:" + password + _n + "[" + _datetime + "] Encrypted:" + encryptedstring + _n + "[" + _datetime + "] Decrypted:" + decryptedstring + _n + "______________________________" + _n);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.ToString(), "An error in the decrypting has occurred!");
                    }
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
          qrInput.ForeColor = Color.Gray;
          qrInput.Text = "Enter Input Here...";
          massDeString.ForeColor = Color.Gray;
          massDeString.Text = "Enter string here, lines seperate strings...";
          massString.ForeColor = Color.Gray;
          massString.Text = "Enter string here, lines seperate strings...";

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Form3 f3 = new Form3();
            f3._theme = _theme;
            f3.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(encryptOutput.Text))
            {
                encryptOutput.SelectAll();
                encryptOutput.Copy();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Form3 f3 = new Form3();
            f3._theme = _theme;
            f3.ShowDialog();
            e.Cancel = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(decryptOutput.Text))
            {
                decryptOutput.SelectAll();
                decryptOutput.Copy();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {           
            if (!string.IsNullOrWhiteSpace(qrOutput.Text))
            {
                qrOutput.SelectAll();
                qrOutput.Copy();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(massOutput.Text))
            {
                massOutput.SelectAll();
                massOutput.Copy();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(massDeOutput.Text))
            {
                massDeOutput.SelectAll();
                massDeOutput.Copy();
            }
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            Form4 f4 = new Form4();
            f4._theme = _theme;
            f4.ShowDialog();
        }

        private void lavenderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _theme = "LavenderTheme";
            menuStrip1.Renderer = new LavenderTheme.MyRenderer();
            button1.BackColor = Color.FromArgb(187, 134, 252);
            button2.BackColor = Color.FromArgb(187, 134, 252);
            button3.BackColor = Color.FromArgb(187, 134, 252);
            button4.BackColor = Color.FromArgb(187, 134, 252);
            button5.BackColor = Color.FromArgb(187, 134, 252);
            button6.BackColor = Color.FromArgb(187, 134, 252);
            button8.BackColor = Color.FromArgb(187, 134, 252);
            encryptBtn.BackColor = Color.FromArgb(187, 134, 252);
            decryptBtn.BackColor = Color.FromArgb(187, 134, 252);
            massDecode.BackColor = Color.FromArgb(187, 134, 252);
            massEncode.BackColor = Color.FromArgb(187, 134, 252);
            qrDecode.BackColor = Color.FromArgb(187, 134, 252);
            qrEncode.BackColor = Color.FromArgb(187, 134, 252);

            tabControl1.DrawMode = TabDrawMode.OwnerDrawFixed;
            tabControl1.DrawItem += new DrawItemEventHandler(DrawOnTab);
        }

        private void jadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _theme = "JadeTheme";
            menuStrip1.Renderer = new JadeTheme.MyRenderer();
            button1.BackColor = Color.FromArgb(0,168,107);
            button2.BackColor = Color.FromArgb(0, 168, 107);
            button3.BackColor = Color.FromArgb(0, 168, 107);
            button4.BackColor = Color.FromArgb(0, 168, 107);
            button5.BackColor = Color.FromArgb(0, 168, 107);
            button6.BackColor = Color.FromArgb(0, 168, 107);
            button8.BackColor = Color.FromArgb(0, 168, 107);
            encryptBtn.BackColor = Color.FromArgb(0, 168, 107);
            decryptBtn.BackColor = Color.FromArgb(0, 168, 107);
            massDecode.BackColor = Color.FromArgb(0, 168, 107);
            massEncode.BackColor = Color.FromArgb(0, 168, 107);
            qrDecode.BackColor = Color.FromArgb(0, 168, 107);
            qrEncode.BackColor = Color.FromArgb(0, 168, 107);
            //this.tabControl1 = new TabControlsDarkJade.DotNetBarTabControlDarkJade();
            //private TabControlsDarkJade.DotNetBarTabControlDarkJade tabControl1;
        }

        private void skyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _theme = "SkyTheme";
            menuStrip1.Renderer = new SkyTheme.MyRenderer();
            button1.BackColor = Color.FromArgb(0, 122, 204);
            button2.BackColor = Color.FromArgb(0, 122, 204);
            button3.BackColor = Color.FromArgb(0, 122, 204);
            button4.BackColor = Color.FromArgb(0, 122, 204);
            button5.BackColor = Color.FromArgb(0, 122, 204);
            button6.BackColor = Color.FromArgb(0, 122, 204);
            button8.BackColor = Color.FromArgb(0, 122, 204);
            encryptBtn.BackColor = Color.FromArgb(0, 122, 204);
            decryptBtn.BackColor = Color.FromArgb(0, 122, 204);
            massDecode.BackColor = Color.FromArgb(0, 122, 204);
            massEncode.BackColor = Color.FromArgb(0, 122, 204);
            qrDecode.BackColor = Color.FromArgb(0, 122, 204);
            qrEncode.BackColor = Color.FromArgb(0, 122, 204);
        }

        private void crimsonToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _theme = "CrimsonTheme";
            menuStrip1.Renderer = new CrimsonTheme.MyRenderer();
            button1.BackColor = Color.FromArgb(221, 0, 49);
            button2.BackColor = Color.FromArgb(221, 0, 49);
            button3.BackColor = Color.FromArgb(221, 0, 49);
            button4.BackColor = Color.FromArgb(221, 0, 49);
            button5.BackColor = Color.FromArgb(221, 0, 49);
            button6.BackColor = Color.FromArgb(221, 0, 49);
            button8.BackColor = Color.FromArgb(221, 0, 49);
            encryptBtn.BackColor = Color.FromArgb(221, 0, 49);
            decryptBtn.BackColor = Color.FromArgb(221, 0, 49);
            massDecode.BackColor = Color.FromArgb(221, 0, 49);
            massEncode.BackColor = Color.FromArgb(221, 0, 49);
            qrDecode.BackColor = Color.FromArgb(221, 0, 49);
            qrEncode.BackColor = Color.FromArgb(221, 0, 49);
        }
    }
}
