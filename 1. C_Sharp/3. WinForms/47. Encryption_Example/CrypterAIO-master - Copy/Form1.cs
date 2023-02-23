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
        public Form1()
        {
            InitializeComponent();
        }

        private void encryptToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gBdecryption.Visible = false;
            gBencryption.Visible = true;
            gBqrcoder.Visible = false;
            gBmassdecrypt.Visible = false;
            gBmassEncrypt.Visible = false;
            decryptSecret.Text = "";
            decryptString.Text = "";
            decryptOutput.Text = "";
        }

        private void encryptBtn_Click(object sender, EventArgs e)
        {
            try
            {
                string password = encryptSecret.Text;
                string plaintext = encryptString.Text;
                string encryptedstring = StringCipher.Encrypt(plaintext, password);
                encryptOutput.Text = encryptedstring;
            }
            catch
            {
                MessageBox.Show("An error in the encrypting has occurred!");
                Environment.Exit(0);
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
            }
            catch
            {
                MessageBox.Show("An error in the decrypting has occurred!");
                Environment.Exit(0);
            }
        }

        private void decryptToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gBencryption.Visible = false;
            gBdecryption.Visible = true;
            gBqrcoder.Visible = false;
            gBmassdecrypt.Visible = false;
            gBmassEncrypt.Visible = false;
            encryptSecret.Text = "";
            encryptString.Text = "";
            encryptOutput.Text = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gBencryption.Visible = false;
            gBmassdecrypt.Visible = false;
            gBdecryption.Visible = false;
            gBqrcoder.Visible = false;
            gBmassEncrypt.Visible = false;
        }

        private void qrInput_Click(object sender, EventArgs e)
        {
            if (qrInput.Text == "Enter Input Here...")
            {
                qrInput.Text = "";
                qrInput.ForeColor = Color.White;
            }
        }

        private void qRCoderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gBdecryption.Visible = false;
            gBencryption.Visible = false;
            gBmassdecrypt.Visible = false;
            gBqrcoder.Visible = true;
            gBmassEncrypt.Visible = false;
            qrInput.ForeColor = Color.Gray;
            qrInput.Text = "Enter Input Here...";
        }

        private void qrEncode_Click(object sender, EventArgs e)
        {
            string password = qrSecret.Text;
            string plaintext = qrInput.Text;
            string encryptedstring = StringCipher.Encrypt(plaintext, password);

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
                catch
                {
                    MessageBox.Show("An error in the encoding has occurred!");
                    Environment.Exit(0);
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
                    }
                }
                catch
                {
                    MessageBox.Show("An error in the decoding has occurred!");
                    Environment.Exit(0);
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

        private void MassEncryptToolStripMenuItem_Click(object sender, EventArgs e)
        {
            gBdecryption.Visible = false;
            gBencryption.Visible = false;
            gBqrcoder.Visible = false;
            gBmassdecrypt.Visible = false;
            gBmassEncrypt.Visible = true;
            massString.ForeColor = Color.Gray;
            massString.Text = "Enter string here, lines seperate strings...";
        }

        private void massEncode_Click(object sender, EventArgs e)
        {
            using (StringReader reader = new StringReader(massString.Text))
            {
                string line;
                massOutput.Text = "";
                while ((line = reader.ReadLine()) != null)
                    {
                    try
                        {
                            string password = massSecret.Text;
                            string plaintext = line;
                            string encryptedstring = StringCipher.Encrypt(plaintext, password);
                            massOutput.Text = massOutput.Text + encryptedstring + Environment.NewLine;
                        }
                    catch
                    {
                        MessageBox.Show("An error in the encrypting has occurred!");
                        Environment.Exit(0);
                    }
                }
            }
        }

        private void MassDecryptToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            gBdecryption.Visible = false;
            gBencryption.Visible = false;
            gBqrcoder.Visible = false;
            gBmassdecrypt.Visible = true;
            gBmassEncrypt.Visible = false;
            massDeString.ForeColor = Color.Gray;
            massDeString.Text = "Enter string here, lines seperate strings...";
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
                    }
                    catch
                    {
                        MessageBox.Show("An error in the decrypting has occurred!");
                        Environment.Exit(0);
                    }
                }
            }
        }
    }
}
