namespace CrypterAIO
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.AboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.lavenderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.jadeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.skyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.crimsonToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sfd1 = new System.Windows.Forms.SaveFileDialog();
            this.ofd1 = new System.Windows.Forms.OpenFileDialog();
            this.tabControl1 = new CrypterAIO.DotNetBarTabControlDark();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.button1 = new System.Windows.Forms.Button();
            this.gBencryption = new System.Windows.Forms.GroupBox();
            this.encryptSecret = new System.Windows.Forms.TextBox();
            this.encryptString = new System.Windows.Forms.TextBox();
            this.encryptBtn = new System.Windows.Forms.Button();
            this.encryptOutput = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.button2 = new System.Windows.Forms.Button();
            this.gBdecryption = new System.Windows.Forms.GroupBox();
            this.decryptSecret = new System.Windows.Forms.TextBox();
            this.decryptString = new System.Windows.Forms.TextBox();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.decryptOutput = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.button3 = new System.Windows.Forms.Button();
            this.gBqrcoder = new System.Windows.Forms.GroupBox();
            this.qrSecret = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.qrPicture = new System.Windows.Forms.PictureBox();
            this.qrOutput = new System.Windows.Forms.RichTextBox();
            this.qrInput = new System.Windows.Forms.RichTextBox();
            this.qrDecode = new System.Windows.Forms.Button();
            this.qrEncode = new System.Windows.Forms.Button();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.button4 = new System.Windows.Forms.Button();
            this.gBmassEncrypt = new System.Windows.Forms.GroupBox();
            this.massSecret = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.massOutput = new System.Windows.Forms.RichTextBox();
            this.massString = new System.Windows.Forms.RichTextBox();
            this.massEncode = new System.Windows.Forms.Button();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.button5 = new System.Windows.Forms.Button();
            this.gBmassdecrypt = new System.Windows.Forms.GroupBox();
            this.massDeSecret = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.massDeOutput = new System.Windows.Forms.RichTextBox();
            this.massDeString = new System.Windows.Forms.RichTextBox();
            this.massDecode = new System.Windows.Forms.Button();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.button8 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button6 = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.gBencryption.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.gBdecryption.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.gBqrcoder.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.qrPicture)).BeginInit();
            this.tabPage4.SuspendLayout();
            this.gBmassEncrypt.SuspendLayout();
            this.tabPage5.SuspendLayout();
            this.gBmassdecrypt.SuspendLayout();
            this.tabPage6.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.AboutToolStripMenuItem,
            this.toolStripMenuItem2,
            this.toolStripMenuItem3});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(4, 2, 0, 2);
            this.menuStrip1.ShowItemToolTips = true;
            this.menuStrip1.Size = new System.Drawing.Size(608, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.toolStripMenuItem1.ForeColor = System.Drawing.Color.White;
            this.toolStripMenuItem1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem1.Image")));
            this.toolStripMenuItem1.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(56, 20);
            this.toolStripMenuItem1.Text = "Exit";
            this.toolStripMenuItem1.ToolTipText = "Exit Application";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // AboutToolStripMenuItem
            // 
            this.AboutToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AboutToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.AboutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("AboutToolStripMenuItem.Image")));
            this.AboutToolStripMenuItem.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.AboutToolStripMenuItem.Name = "AboutToolStripMenuItem";
            this.AboutToolStripMenuItem.Size = new System.Drawing.Size(69, 20);
            this.AboutToolStripMenuItem.Text = "About";
            this.AboutToolStripMenuItem.ToolTipText = "About The Application";
            this.AboutToolStripMenuItem.Click += new System.EventHandler(this.AboutToolStripMenuItem_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.toolStripMenuItem2.ForeColor = System.Drawing.Color.White;
            this.toolStripMenuItem2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem2.Image")));
            this.toolStripMenuItem2.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(81, 20);
            this.toolStripMenuItem2.Text = "Updates";
            this.toolStripMenuItem2.ToolTipText = "Check For Updates";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItem2_Click);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lavenderToolStripMenuItem,
            this.jadeToolStripMenuItem,
            this.skyToolStripMenuItem,
            this.crimsonToolStripMenuItem});
            this.toolStripMenuItem3.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.toolStripMenuItem3.ForeColor = System.Drawing.Color.White;
            this.toolStripMenuItem3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem3.Image")));
            this.toolStripMenuItem3.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(79, 20);
            this.toolStripMenuItem3.Text = "Themes";
            this.toolStripMenuItem3.ToolTipText = "Application Themes";
            // 
            // lavenderToolStripMenuItem
            // 
            this.lavenderToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.lavenderToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.lavenderToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("lavenderToolStripMenuItem.Image")));
            this.lavenderToolStripMenuItem.Name = "lavenderToolStripMenuItem";
            this.lavenderToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.lavenderToolStripMenuItem.Text = "Lavender";
            this.lavenderToolStripMenuItem.Click += new System.EventHandler(this.lavenderToolStripMenuItem_Click);
            // 
            // jadeToolStripMenuItem
            // 
            this.jadeToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.jadeToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.jadeToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("jadeToolStripMenuItem.Image")));
            this.jadeToolStripMenuItem.Name = "jadeToolStripMenuItem";
            this.jadeToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.jadeToolStripMenuItem.Text = "Jade";
            this.jadeToolStripMenuItem.Click += new System.EventHandler(this.jadeToolStripMenuItem_Click);
            // 
            // skyToolStripMenuItem
            // 
            this.skyToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.skyToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.skyToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("skyToolStripMenuItem.Image")));
            this.skyToolStripMenuItem.Name = "skyToolStripMenuItem";
            this.skyToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.skyToolStripMenuItem.Text = "Sky";
            this.skyToolStripMenuItem.Click += new System.EventHandler(this.skyToolStripMenuItem_Click);
            // 
            // crimsonToolStripMenuItem
            // 
            this.crimsonToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.crimsonToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.crimsonToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("crimsonToolStripMenuItem.Image")));
            this.crimsonToolStripMenuItem.Name = "crimsonToolStripMenuItem";
            this.crimsonToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.crimsonToolStripMenuItem.Text = "Crimson";
            this.crimsonToolStripMenuItem.Click += new System.EventHandler(this.crimsonToolStripMenuItem_Click);
            // 
            // ofd1
            // 
            this.ofd1.FileName = "openFileDialog1";
            // 
            // tabControl1
            // 
            this.tabControl1.Alignment = System.Windows.Forms.TabAlignment.Left;
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Controls.Add(this.tabPage5);
            this.tabControl1.Controls.Add(this.tabPage6);
            this.tabControl1.DrawMode = System.Windows.Forms.TabDrawMode.OwnerDrawFixed;
            this.tabControl1.ItemSize = new System.Drawing.Size(44, 136);
            this.tabControl1.Location = new System.Drawing.Point(0, 27);
            this.tabControl1.Multiline = true;
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(611, 361);
            this.tabControl1.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabControl1.TabIndex = 15;
            this.tabControl1.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.tabControl1_DrawItem);
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage1.Controls.Add(this.button1);
            this.tabPage1.Controls.Add(this.gBencryption);
            this.tabPage1.Location = new System.Drawing.Point(140, 4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(467, 353);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Encrypt";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button1.ForeColor = System.Drawing.Color.Black;
            this.button1.Location = new System.Drawing.Point(400, 324);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(62, 26);
            this.button1.TabIndex = 17;
            this.button1.Text = "Copy";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // gBencryption
            // 
            this.gBencryption.Controls.Add(this.encryptSecret);
            this.gBencryption.Controls.Add(this.encryptString);
            this.gBencryption.Controls.Add(this.encryptBtn);
            this.gBencryption.Controls.Add(this.encryptOutput);
            this.gBencryption.Controls.Add(this.label2);
            this.gBencryption.Controls.Add(this.label1);
            this.gBencryption.ForeColor = System.Drawing.Color.White;
            this.gBencryption.Location = new System.Drawing.Point(5, 5);
            this.gBencryption.Margin = new System.Windows.Forms.Padding(2);
            this.gBencryption.Name = "gBencryption";
            this.gBencryption.Padding = new System.Windows.Forms.Padding(2);
            this.gBencryption.Size = new System.Drawing.Size(460, 315);
            this.gBencryption.TabIndex = 8;
            this.gBencryption.TabStop = false;
            this.gBencryption.Text = "Encryption";
            // 
            // encryptSecret
            // 
            this.encryptSecret.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.encryptSecret.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.encryptSecret.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.encryptSecret.Location = new System.Drawing.Point(57, 24);
            this.encryptSecret.Margin = new System.Windows.Forms.Padding(2);
            this.encryptSecret.Name = "encryptSecret";
            this.encryptSecret.Size = new System.Drawing.Size(392, 20);
            this.encryptSecret.TabIndex = 5;
            // 
            // encryptString
            // 
            this.encryptString.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.encryptString.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.encryptString.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.encryptString.Location = new System.Drawing.Point(57, 54);
            this.encryptString.Margin = new System.Windows.Forms.Padding(2);
            this.encryptString.Name = "encryptString";
            this.encryptString.Size = new System.Drawing.Size(392, 20);
            this.encryptString.TabIndex = 6;
            // 
            // encryptBtn
            // 
            this.encryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.encryptBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.encryptBtn.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.encryptBtn.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.encryptBtn.ForeColor = System.Drawing.Color.Black;
            this.encryptBtn.Location = new System.Drawing.Point(10, 89);
            this.encryptBtn.Margin = new System.Windows.Forms.Padding(2);
            this.encryptBtn.Name = "encryptBtn";
            this.encryptBtn.Size = new System.Drawing.Size(438, 28);
            this.encryptBtn.TabIndex = 1;
            this.encryptBtn.Text = "Encrypt";
            this.encryptBtn.UseVisualStyleBackColor = false;
            this.encryptBtn.Click += new System.EventHandler(this.encryptBtn_Click_1);
            // 
            // encryptOutput
            // 
            this.encryptOutput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.encryptOutput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.encryptOutput.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.encryptOutput.HideSelection = false;
            this.encryptOutput.Location = new System.Drawing.Point(10, 121);
            this.encryptOutput.Margin = new System.Windows.Forms.Padding(2);
            this.encryptOutput.Name = "encryptOutput";
            this.encryptOutput.ReadOnly = true;
            this.encryptOutput.Size = new System.Drawing.Size(439, 181);
            this.encryptOutput.TabIndex = 2;
            this.encryptOutput.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(10, 24);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "Secret:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(10, 53);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 15);
            this.label1.TabIndex = 3;
            this.label1.Text = "String:";
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Controls.Add(this.gBdecryption);
            this.tabPage2.Location = new System.Drawing.Point(140, 4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(467, 353);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Decrypt";
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button2.ForeColor = System.Drawing.Color.Black;
            this.button2.Location = new System.Drawing.Point(400, 324);
            this.button2.Margin = new System.Windows.Forms.Padding(2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(62, 26);
            this.button2.TabIndex = 17;
            this.button2.Text = "Copy";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // gBdecryption
            // 
            this.gBdecryption.Controls.Add(this.decryptSecret);
            this.gBdecryption.Controls.Add(this.decryptString);
            this.gBdecryption.Controls.Add(this.decryptBtn);
            this.gBdecryption.Controls.Add(this.decryptOutput);
            this.gBdecryption.Controls.Add(this.label3);
            this.gBdecryption.Controls.Add(this.label4);
            this.gBdecryption.ForeColor = System.Drawing.Color.White;
            this.gBdecryption.Location = new System.Drawing.Point(5, 5);
            this.gBdecryption.Margin = new System.Windows.Forms.Padding(2);
            this.gBdecryption.Name = "gBdecryption";
            this.gBdecryption.Padding = new System.Windows.Forms.Padding(2);
            this.gBdecryption.Size = new System.Drawing.Size(460, 315);
            this.gBdecryption.TabIndex = 8;
            this.gBdecryption.TabStop = false;
            this.gBdecryption.Text = "Decryption";
            // 
            // decryptSecret
            // 
            this.decryptSecret.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.decryptSecret.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.decryptSecret.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.decryptSecret.Location = new System.Drawing.Point(57, 24);
            this.decryptSecret.Margin = new System.Windows.Forms.Padding(2);
            this.decryptSecret.Name = "decryptSecret";
            this.decryptSecret.Size = new System.Drawing.Size(392, 20);
            this.decryptSecret.TabIndex = 5;
            // 
            // decryptString
            // 
            this.decryptString.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.decryptString.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.decryptString.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.decryptString.Location = new System.Drawing.Point(57, 54);
            this.decryptString.Margin = new System.Windows.Forms.Padding(2);
            this.decryptString.Name = "decryptString";
            this.decryptString.Size = new System.Drawing.Size(392, 20);
            this.decryptString.TabIndex = 6;
            // 
            // decryptBtn
            // 
            this.decryptBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.decryptBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.decryptBtn.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.decryptBtn.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.decryptBtn.ForeColor = System.Drawing.Color.Black;
            this.decryptBtn.Location = new System.Drawing.Point(10, 89);
            this.decryptBtn.Margin = new System.Windows.Forms.Padding(2);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(438, 28);
            this.decryptBtn.TabIndex = 1;
            this.decryptBtn.Text = "Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = false;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // decryptOutput
            // 
            this.decryptOutput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.decryptOutput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.decryptOutput.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.decryptOutput.HideSelection = false;
            this.decryptOutput.Location = new System.Drawing.Point(10, 121);
            this.decryptOutput.Margin = new System.Windows.Forms.Padding(2);
            this.decryptOutput.Name = "decryptOutput";
            this.decryptOutput.ReadOnly = true;
            this.decryptOutput.Size = new System.Drawing.Size(439, 181);
            this.decryptOutput.TabIndex = 2;
            this.decryptOutput.Text = "";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(10, 24);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 15);
            this.label3.TabIndex = 4;
            this.label3.Text = "Secret:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(10, 53);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(44, 15);
            this.label4.TabIndex = 3;
            this.label4.Text = "String:";
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage3.Controls.Add(this.button3);
            this.tabPage3.Controls.Add(this.gBqrcoder);
            this.tabPage3.Location = new System.Drawing.Point(140, 4);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(467, 353);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "QR-Coder";
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button3.ForeColor = System.Drawing.Color.Black;
            this.button3.Location = new System.Drawing.Point(400, 324);
            this.button3.Margin = new System.Windows.Forms.Padding(2);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(62, 26);
            this.button3.TabIndex = 17;
            this.button3.Text = "Copy";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // gBqrcoder
            // 
            this.gBqrcoder.Controls.Add(this.qrSecret);
            this.gBqrcoder.Controls.Add(this.label5);
            this.gBqrcoder.Controls.Add(this.qrPicture);
            this.gBqrcoder.Controls.Add(this.qrOutput);
            this.gBqrcoder.Controls.Add(this.qrInput);
            this.gBqrcoder.Controls.Add(this.qrDecode);
            this.gBqrcoder.Controls.Add(this.qrEncode);
            this.gBqrcoder.ForeColor = System.Drawing.Color.White;
            this.gBqrcoder.Location = new System.Drawing.Point(5, 5);
            this.gBqrcoder.Margin = new System.Windows.Forms.Padding(2);
            this.gBqrcoder.Name = "gBqrcoder";
            this.gBqrcoder.Padding = new System.Windows.Forms.Padding(2);
            this.gBqrcoder.Size = new System.Drawing.Size(460, 315);
            this.gBqrcoder.TabIndex = 9;
            this.gBqrcoder.TabStop = false;
            this.gBqrcoder.Text = "QR-Coder";
            // 
            // qrSecret
            // 
            this.qrSecret.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.qrSecret.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.qrSecret.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.qrSecret.Location = new System.Drawing.Point(57, 20);
            this.qrSecret.Margin = new System.Windows.Forms.Padding(2);
            this.qrSecret.Name = "qrSecret";
            this.qrSecret.Size = new System.Drawing.Size(392, 20);
            this.qrSecret.TabIndex = 12;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(8, 21);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(48, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Secret:";
            // 
            // qrPicture
            // 
            this.qrPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.qrPicture.InitialImage = null;
            this.qrPicture.Location = new System.Drawing.Point(344, 188);
            this.qrPicture.Margin = new System.Windows.Forms.Padding(2);
            this.qrPicture.Name = "qrPicture";
            this.qrPicture.Size = new System.Drawing.Size(105, 114);
            this.qrPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.qrPicture.TabIndex = 10;
            this.qrPicture.TabStop = false;
            // 
            // qrOutput
            // 
            this.qrOutput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.qrOutput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.qrOutput.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.qrOutput.HideSelection = false;
            this.qrOutput.Location = new System.Drawing.Point(10, 188);
            this.qrOutput.Margin = new System.Windows.Forms.Padding(2);
            this.qrOutput.Name = "qrOutput";
            this.qrOutput.ReadOnly = true;
            this.qrOutput.Size = new System.Drawing.Size(326, 114);
            this.qrOutput.TabIndex = 9;
            this.qrOutput.Text = "";
            // 
            // qrInput
            // 
            this.qrInput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.qrInput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.qrInput.ForeColor = System.Drawing.SystemColors.ControlDark;
            this.qrInput.Location = new System.Drawing.Point(10, 47);
            this.qrInput.Margin = new System.Windows.Forms.Padding(2);
            this.qrInput.Name = "qrInput";
            this.qrInput.Size = new System.Drawing.Size(439, 90);
            this.qrInput.TabIndex = 8;
            this.qrInput.Text = "Enter String Here...";
            this.qrInput.Click += new System.EventHandler(this.qrInput_Click);
            // 
            // qrDecode
            // 
            this.qrDecode.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.qrDecode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.qrDecode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.qrDecode.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.qrDecode.ForeColor = System.Drawing.Color.Black;
            this.qrDecode.Location = new System.Drawing.Point(232, 149);
            this.qrDecode.Margin = new System.Windows.Forms.Padding(2);
            this.qrDecode.Name = "qrDecode";
            this.qrDecode.Size = new System.Drawing.Size(216, 28);
            this.qrDecode.TabIndex = 7;
            this.qrDecode.Text = "Decode";
            this.qrDecode.UseVisualStyleBackColor = false;
            this.qrDecode.Click += new System.EventHandler(this.qrDecode_Click);
            // 
            // qrEncode
            // 
            this.qrEncode.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.qrEncode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.qrEncode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.qrEncode.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.qrEncode.ForeColor = System.Drawing.Color.Black;
            this.qrEncode.Location = new System.Drawing.Point(10, 149);
            this.qrEncode.Margin = new System.Windows.Forms.Padding(2);
            this.qrEncode.Name = "qrEncode";
            this.qrEncode.Size = new System.Drawing.Size(211, 28);
            this.qrEncode.TabIndex = 1;
            this.qrEncode.Text = "Encode";
            this.qrEncode.UseVisualStyleBackColor = false;
            this.qrEncode.Click += new System.EventHandler(this.qrEncode_Click);
            // 
            // tabPage4
            // 
            this.tabPage4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage4.Controls.Add(this.button4);
            this.tabPage4.Controls.Add(this.gBmassEncrypt);
            this.tabPage4.Location = new System.Drawing.Point(140, 4);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(467, 353);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Mass Encrypt";
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button4.ForeColor = System.Drawing.Color.Black;
            this.button4.Location = new System.Drawing.Point(400, 324);
            this.button4.Margin = new System.Windows.Forms.Padding(2);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(62, 26);
            this.button4.TabIndex = 17;
            this.button4.Text = "Copy";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // gBmassEncrypt
            // 
            this.gBmassEncrypt.Controls.Add(this.massSecret);
            this.gBmassEncrypt.Controls.Add(this.label7);
            this.gBmassEncrypt.Controls.Add(this.massOutput);
            this.gBmassEncrypt.Controls.Add(this.massString);
            this.gBmassEncrypt.Controls.Add(this.massEncode);
            this.gBmassEncrypt.ForeColor = System.Drawing.Color.White;
            this.gBmassEncrypt.Location = new System.Drawing.Point(5, 5);
            this.gBmassEncrypt.Margin = new System.Windows.Forms.Padding(2);
            this.gBmassEncrypt.Name = "gBmassEncrypt";
            this.gBmassEncrypt.Padding = new System.Windows.Forms.Padding(2);
            this.gBmassEncrypt.Size = new System.Drawing.Size(460, 315);
            this.gBmassEncrypt.TabIndex = 13;
            this.gBmassEncrypt.TabStop = false;
            this.gBmassEncrypt.Text = "Mass Encrypt";
            // 
            // massSecret
            // 
            this.massSecret.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massSecret.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.massSecret.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.massSecret.Location = new System.Drawing.Point(57, 20);
            this.massSecret.Margin = new System.Windows.Forms.Padding(2);
            this.massSecret.Name = "massSecret";
            this.massSecret.Size = new System.Drawing.Size(392, 20);
            this.massSecret.TabIndex = 12;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(8, 21);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(48, 13);
            this.label7.TabIndex = 11;
            this.label7.Text = "Secret:";
            // 
            // massOutput
            // 
            this.massOutput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massOutput.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.massOutput.HideSelection = false;
            this.massOutput.Location = new System.Drawing.Point(10, 188);
            this.massOutput.Margin = new System.Windows.Forms.Padding(2);
            this.massOutput.Name = "massOutput";
            this.massOutput.ReadOnly = true;
            this.massOutput.RightMargin = 1000;
            this.massOutput.Size = new System.Drawing.Size(439, 114);
            this.massOutput.TabIndex = 9;
            this.massOutput.Text = "";
            this.massOutput.WordWrap = false;
            // 
            // massString
            // 
            this.massString.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massString.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.massString.ForeColor = System.Drawing.SystemColors.ControlDark;
            this.massString.Location = new System.Drawing.Point(10, 47);
            this.massString.Margin = new System.Windows.Forms.Padding(2);
            this.massString.Name = "massString";
            this.massString.RightMargin = 1000;
            this.massString.Size = new System.Drawing.Size(439, 105);
            this.massString.TabIndex = 8;
            this.massString.Text = "Enter string here, lines seperate strings...";
            this.massString.Click += new System.EventHandler(this.massString_Click);
            // 
            // massEncode
            // 
            this.massEncode.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.massEncode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.massEncode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.massEncode.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.massEncode.ForeColor = System.Drawing.Color.Black;
            this.massEncode.Location = new System.Drawing.Point(10, 156);
            this.massEncode.Margin = new System.Windows.Forms.Padding(2);
            this.massEncode.Name = "massEncode";
            this.massEncode.Size = new System.Drawing.Size(438, 28);
            this.massEncode.TabIndex = 1;
            this.massEncode.Text = "Encrypt";
            this.massEncode.UseVisualStyleBackColor = false;
            this.massEncode.Click += new System.EventHandler(this.massEncode_Click);
            // 
            // tabPage5
            // 
            this.tabPage5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage5.Controls.Add(this.button5);
            this.tabPage5.Controls.Add(this.gBmassdecrypt);
            this.tabPage5.Location = new System.Drawing.Point(140, 4);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage5.Size = new System.Drawing.Size(467, 353);
            this.tabPage5.TabIndex = 4;
            this.tabPage5.Text = "Mass Decrypt";
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button5.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button5.ForeColor = System.Drawing.Color.Black;
            this.button5.Location = new System.Drawing.Point(400, 324);
            this.button5.Margin = new System.Windows.Forms.Padding(2);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(62, 26);
            this.button5.TabIndex = 17;
            this.button5.Text = "Copy";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // gBmassdecrypt
            // 
            this.gBmassdecrypt.Controls.Add(this.massDeSecret);
            this.gBmassdecrypt.Controls.Add(this.label8);
            this.gBmassdecrypt.Controls.Add(this.massDeOutput);
            this.gBmassdecrypt.Controls.Add(this.massDeString);
            this.gBmassdecrypt.Controls.Add(this.massDecode);
            this.gBmassdecrypt.ForeColor = System.Drawing.Color.White;
            this.gBmassdecrypt.Location = new System.Drawing.Point(5, 5);
            this.gBmassdecrypt.Margin = new System.Windows.Forms.Padding(2);
            this.gBmassdecrypt.Name = "gBmassdecrypt";
            this.gBmassdecrypt.Padding = new System.Windows.Forms.Padding(2);
            this.gBmassdecrypt.Size = new System.Drawing.Size(460, 315);
            this.gBmassdecrypt.TabIndex = 14;
            this.gBmassdecrypt.TabStop = false;
            this.gBmassdecrypt.Text = "Mass Decrypt";
            // 
            // massDeSecret
            // 
            this.massDeSecret.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massDeSecret.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.massDeSecret.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.massDeSecret.Location = new System.Drawing.Point(57, 20);
            this.massDeSecret.Margin = new System.Windows.Forms.Padding(2);
            this.massDeSecret.Name = "massDeSecret";
            this.massDeSecret.Size = new System.Drawing.Size(392, 20);
            this.massDeSecret.TabIndex = 12;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(8, 21);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(48, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Secret:";
            // 
            // massDeOutput
            // 
            this.massDeOutput.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massDeOutput.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.massDeOutput.HideSelection = false;
            this.massDeOutput.Location = new System.Drawing.Point(10, 188);
            this.massDeOutput.Margin = new System.Windows.Forms.Padding(2);
            this.massDeOutput.Name = "massDeOutput";
            this.massDeOutput.ReadOnly = true;
            this.massDeOutput.RightMargin = 1000;
            this.massDeOutput.Size = new System.Drawing.Size(439, 114);
            this.massDeOutput.TabIndex = 9;
            this.massDeOutput.Text = "";
            this.massDeOutput.WordWrap = false;
            // 
            // massDeString
            // 
            this.massDeString.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.massDeString.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.massDeString.ForeColor = System.Drawing.Color.Gray;
            this.massDeString.Location = new System.Drawing.Point(10, 47);
            this.massDeString.Margin = new System.Windows.Forms.Padding(2);
            this.massDeString.Name = "massDeString";
            this.massDeString.RightMargin = 1000;
            this.massDeString.Size = new System.Drawing.Size(439, 105);
            this.massDeString.TabIndex = 8;
            this.massDeString.Text = "Enter string here, lines seperate strings...";
            this.massDeString.Click += new System.EventHandler(this.massDeString_Click);
            // 
            // massDecode
            // 
            this.massDecode.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.massDecode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.massDecode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.massDecode.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.massDecode.ForeColor = System.Drawing.Color.Black;
            this.massDecode.Location = new System.Drawing.Point(10, 156);
            this.massDecode.Margin = new System.Windows.Forms.Padding(2);
            this.massDecode.Name = "massDecode";
            this.massDecode.Size = new System.Drawing.Size(438, 28);
            this.massDecode.TabIndex = 1;
            this.massDecode.Text = "Decrypt";
            this.massDecode.UseVisualStyleBackColor = false;
            this.massDecode.Click += new System.EventHandler(this.massDecode_Click);
            // 
            // tabPage6
            // 
            this.tabPage6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.tabPage6.Controls.Add(this.button8);
            this.tabPage6.Controls.Add(this.groupBox1);
            this.tabPage6.Controls.Add(this.button6);
            this.tabPage6.Location = new System.Drawing.Point(140, 4);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage6.Size = new System.Drawing.Size(467, 353);
            this.tabPage6.TabIndex = 5;
            this.tabPage6.Text = "History";
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button8.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button8.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button8.ForeColor = System.Drawing.Color.Black;
            this.button8.Location = new System.Drawing.Point(334, 324);
            this.button8.Margin = new System.Windows.Forms.Padding(2);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(62, 26);
            this.button8.TabIndex = 20;
            this.button8.Text = "Save";
            this.button8.UseVisualStyleBackColor = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.richTextBox1);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(5, 5);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox1.Size = new System.Drawing.Size(460, 315);
            this.groupBox1.TabIndex = 19;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "History";
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.richTextBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.richTextBox1.ForeColor = System.Drawing.Color.White;
            this.richTextBox1.HideSelection = false;
            this.richTextBox1.Location = new System.Drawing.Point(5, 18);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
            this.richTextBox1.Size = new System.Drawing.Size(446, 292);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(187)))), ((int)(((byte)(134)))), ((int)(((byte)(252)))));
            this.button6.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button6.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.button6.ForeColor = System.Drawing.Color.Black;
            this.button6.Location = new System.Drawing.Point(400, 324);
            this.button6.Margin = new System.Windows.Forms.Padding(2);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(62, 26);
            this.button6.TabIndex = 18;
            this.button6.Text = "Copy";
            this.button6.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(18)))), ((int)(((byte)(18)))), ((int)(((byte)(18)))));
            this.ClientSize = new System.Drawing.Size(608, 384);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "E2E Crypter";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.gBencryption.ResumeLayout(false);
            this.gBencryption.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.gBdecryption.ResumeLayout(false);
            this.gBdecryption.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.gBqrcoder.ResumeLayout(false);
            this.gBqrcoder.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.qrPicture)).EndInit();
            this.tabPage4.ResumeLayout(false);
            this.gBmassEncrypt.ResumeLayout(false);
            this.gBmassEncrypt.PerformLayout();
            this.tabPage5.ResumeLayout(false);
            this.gBmassdecrypt.ResumeLayout(false);
            this.gBmassdecrypt.PerformLayout();
            this.tabPage6.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem AboutToolStripMenuItem;
        private System.Windows.Forms.GroupBox gBdecryption;
        private System.Windows.Forms.TextBox decryptSecret;
        private System.Windows.Forms.TextBox decryptString;
        private System.Windows.Forms.Button decryptBtn;
        private System.Windows.Forms.RichTextBox decryptOutput;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox gBqrcoder;
        private System.Windows.Forms.RichTextBox qrOutput;
        private System.Windows.Forms.RichTextBox qrInput;
        private System.Windows.Forms.Button qrDecode;
        private System.Windows.Forms.Button qrEncode;
        private System.Windows.Forms.SaveFileDialog sfd1;
        private System.Windows.Forms.OpenFileDialog ofd1;
        private System.Windows.Forms.PictureBox qrPicture;
        private System.Windows.Forms.TextBox qrSecret;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox gBmassEncrypt;
        private System.Windows.Forms.TextBox massSecret;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.RichTextBox massOutput;
        private System.Windows.Forms.RichTextBox massString;
        private System.Windows.Forms.Button massEncode;
        private System.Windows.Forms.GroupBox gBmassdecrypt;
        private System.Windows.Forms.TextBox massDeSecret;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RichTextBox massDeOutput;
        private System.Windows.Forms.RichTextBox massDeString;
        private System.Windows.Forms.Button massDecode;
        //private TabControlsDark.DotNetBarTabControlDark tabControl1;
        private CrypterAIO.DotNetBarTabControlDark tabControl1;
        //private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.GroupBox gBencryption;
        private System.Windows.Forms.TextBox encryptSecret;
        private System.Windows.Forms.TextBox encryptString;
        private System.Windows.Forms.Button encryptBtn;
        private System.Windows.Forms.RichTextBox encryptOutput;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem lavenderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem jadeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem skyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem crimsonToolStripMenuItem;
    }
}

