namespace Maths_Testing_Application
{
    partial class MainForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tCPConnectionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hTTPConnectionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this.toolStripStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.richTextBox = new System.Windows.Forms.RichTextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.Nextbutton = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.panel2 = new System.Windows.Forms.Panel();
            this.StartTestbutton = new System.Windows.Forms.Button();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.Nextquestionbutton1 = new System.Windows.Forms.Button();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.panel4 = new System.Windows.Forms.Panel();
            this.Backbutton2 = new System.Windows.Forms.Button();
            this.Nextquestionbutton2 = new System.Windows.Forms.Button();
            this.TCPtimer = new System.Windows.Forms.Timer(this.components);
            this.ServerChecktimer = new System.Windows.Forms.Timer(this.components);
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel5 = new System.Windows.Forms.Panel();
            this.panel6 = new System.Windows.Forms.Panel();
            this.panel7 = new System.Windows.Forms.Panel();
            this.panel8 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label6 = new System.Windows.Forms.Label();
            this.TandCrichTextBox = new System.Windows.Forms.RichTextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.panel2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.panel3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel6.SuspendLayout();
            this.panel7.SuspendLayout();
            this.panel8.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem,
            this.settingsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1282, 36);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.aboutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("aboutToolStripMenuItem.Image")));
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(102, 30);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tCPConnectionToolStripMenuItem,
            this.hTTPConnectionToolStripMenuItem});
            this.settingsToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.settingsToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("settingsToolStripMenuItem.Image")));
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(116, 30);
            this.settingsToolStripMenuItem.Text = "Settings";
            // 
            // tCPConnectionToolStripMenuItem
            // 
            this.tCPConnectionToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("tCPConnectionToolStripMenuItem.Image")));
            this.tCPConnectionToolStripMenuItem.Name = "tCPConnectionToolStripMenuItem";
            this.tCPConnectionToolStripMenuItem.Size = new System.Drawing.Size(250, 34);
            this.tCPConnectionToolStripMenuItem.Text = "TCP Connection";
            // 
            // hTTPConnectionToolStripMenuItem
            // 
            this.hTTPConnectionToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("hTTPConnectionToolStripMenuItem.Image")));
            this.hTTPConnectionToolStripMenuItem.Name = "hTTPConnectionToolStripMenuItem";
            this.hTTPConnectionToolStripMenuItem.Size = new System.Drawing.Size(250, 34);
            this.hTTPConnectionToolStripMenuItem.Text = "HTTP Connection";
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripProgressBar,
            this.toolStripStatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 1267);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1282, 32);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripProgressBar
            // 
            this.toolStripProgressBar.Name = "toolStripProgressBar";
            this.toolStripProgressBar.Size = new System.Drawing.Size(100, 24);
            // 
            // toolStripStatusLabel
            // 
            this.toolStripStatusLabel.BackColor = System.Drawing.Color.Transparent;
            this.toolStripStatusLabel.Name = "toolStripStatusLabel";
            this.toolStripStatusLabel.Size = new System.Drawing.Size(60, 25);
            this.toolStripStatusLabel.Text = "Ready";
            // 
            // richTextBox
            // 
            this.richTextBox.BackColor = System.Drawing.Color.Black;
            this.richTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBox.ForeColor = System.Drawing.Color.White;
            this.richTextBox.Location = new System.Drawing.Point(3, 22);
            this.richTextBox.Name = "richTextBox";
            this.richTextBox.ReadOnly = true;
            this.richTextBox.Size = new System.Drawing.Size(1276, 175);
            this.richTextBox.TabIndex = 3;
            this.richTextBox.Text = "";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.richTextBox);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(0, 1067);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(1282, 200);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Log";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 36);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1282, 1031);
            this.tabControl1.TabIndex = 7;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(34)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.tabPage1.Controls.Add(this.pictureBox1);
            this.tabPage1.Controls.Add(this.panel8);
            this.tabPage1.Controls.Add(this.panel7);
            this.tabPage1.Controls.Add(this.panel6);
            this.tabPage1.Controls.Add(this.panel5);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.panel1);
            this.tabPage1.Location = new System.Drawing.Point(4, 29);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1274, 998);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Home";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Dock = System.Windows.Forms.DockStyle.Left;
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(0, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(92, 20);
            this.label3.TabIndex = 3;
            this.label3.Text = "Paragraph2";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Left;
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(0, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(92, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Paragraph1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(8, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(121, 32);
            this.label1.TabIndex = 1;
            this.label1.Text = "Heading";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.Nextbutton);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(3, 953);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1268, 42);
            this.panel1.TabIndex = 0;
            // 
            // Nextbutton
            // 
            this.Nextbutton.BackColor = System.Drawing.Color.SkyBlue;
            this.Nextbutton.Dock = System.Windows.Forms.DockStyle.Right;
            this.Nextbutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Nextbutton.ForeColor = System.Drawing.Color.Black;
            this.Nextbutton.Location = new System.Drawing.Point(1128, 0);
            this.Nextbutton.Name = "Nextbutton";
            this.Nextbutton.Size = new System.Drawing.Size(140, 42);
            this.Nextbutton.TabIndex = 3;
            this.Nextbutton.Text = "Next";
            this.Nextbutton.UseVisualStyleBackColor = false;
            this.Nextbutton.Click += new System.EventHandler(this.Nextbutton_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(34)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.tabPage2.Controls.Add(this.TandCrichTextBox);
            this.tabPage2.Controls.Add(this.panel2);
            this.tabPage2.Location = new System.Drawing.Point(4, 29);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1274, 998);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "T&C\'s";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label7);
            this.panel2.Controls.Add(this.StartTestbutton);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(3, 953);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1268, 42);
            this.panel2.TabIndex = 1;
            // 
            // StartTestbutton
            // 
            this.StartTestbutton.BackColor = System.Drawing.Color.SkyBlue;
            this.StartTestbutton.Dock = System.Windows.Forms.DockStyle.Right;
            this.StartTestbutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.StartTestbutton.ForeColor = System.Drawing.Color.Black;
            this.StartTestbutton.Location = new System.Drawing.Point(1128, 0);
            this.StartTestbutton.Name = "StartTestbutton";
            this.StartTestbutton.Size = new System.Drawing.Size(140, 42);
            this.StartTestbutton.TabIndex = 3;
            this.StartTestbutton.Text = "Start Test";
            this.StartTestbutton.UseVisualStyleBackColor = false;
            this.StartTestbutton.Click += new System.EventHandler(this.StartTestbutton_Click);
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(34)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.tabPage3.Controls.Add(this.groupBox2);
            this.tabPage3.Controls.Add(this.panel3);
            this.tabPage3.Location = new System.Drawing.Point(4, 29);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(1274, 998);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Q1";
            // 
            // groupBox2
            // 
            this.groupBox2.ForeColor = System.Drawing.Color.White;
            this.groupBox2.Location = new System.Drawing.Point(8, 6);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(1109, 386);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Question 1";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.Nextquestionbutton1);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel3.Location = new System.Drawing.Point(3, 953);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1268, 42);
            this.panel3.TabIndex = 1;
            // 
            // Nextquestionbutton1
            // 
            this.Nextquestionbutton1.BackColor = System.Drawing.Color.SkyBlue;
            this.Nextquestionbutton1.Dock = System.Windows.Forms.DockStyle.Right;
            this.Nextquestionbutton1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Nextquestionbutton1.ForeColor = System.Drawing.Color.Black;
            this.Nextquestionbutton1.Location = new System.Drawing.Point(1128, 0);
            this.Nextquestionbutton1.Name = "Nextquestionbutton1";
            this.Nextquestionbutton1.Size = new System.Drawing.Size(140, 42);
            this.Nextquestionbutton1.TabIndex = 3;
            this.Nextquestionbutton1.Text = "Next Question";
            this.Nextquestionbutton1.UseVisualStyleBackColor = false;
            this.Nextquestionbutton1.Click += new System.EventHandler(this.Nextquestionbutton1_Click);
            // 
            // tabPage4
            // 
            this.tabPage4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(34)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.tabPage4.Controls.Add(this.groupBox3);
            this.tabPage4.Controls.Add(this.panel4);
            this.tabPage4.Location = new System.Drawing.Point(4, 29);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(1274, 998);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Q2";
            // 
            // groupBox3
            // 
            this.groupBox3.ForeColor = System.Drawing.Color.White;
            this.groupBox3.Location = new System.Drawing.Point(8, 6);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(1109, 386);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Question 2";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.Backbutton2);
            this.panel4.Controls.Add(this.Nextquestionbutton2);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel4.Location = new System.Drawing.Point(3, 953);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(1268, 42);
            this.panel4.TabIndex = 2;
            // 
            // Backbutton2
            // 
            this.Backbutton2.BackColor = System.Drawing.Color.SkyBlue;
            this.Backbutton2.Dock = System.Windows.Forms.DockStyle.Left;
            this.Backbutton2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Backbutton2.ForeColor = System.Drawing.Color.Black;
            this.Backbutton2.Location = new System.Drawing.Point(0, 0);
            this.Backbutton2.Name = "Backbutton2";
            this.Backbutton2.Size = new System.Drawing.Size(140, 42);
            this.Backbutton2.TabIndex = 4;
            this.Backbutton2.Text = "Back";
            this.Backbutton2.UseVisualStyleBackColor = false;
            this.Backbutton2.Click += new System.EventHandler(this.Backbutton2_Click);
            // 
            // Nextquestionbutton2
            // 
            this.Nextquestionbutton2.BackColor = System.Drawing.Color.SkyBlue;
            this.Nextquestionbutton2.Dock = System.Windows.Forms.DockStyle.Right;
            this.Nextquestionbutton2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Nextquestionbutton2.ForeColor = System.Drawing.Color.Black;
            this.Nextquestionbutton2.Location = new System.Drawing.Point(1128, 0);
            this.Nextquestionbutton2.Name = "Nextquestionbutton2";
            this.Nextquestionbutton2.Size = new System.Drawing.Size(140, 42);
            this.Nextquestionbutton2.TabIndex = 3;
            this.Nextquestionbutton2.Text = "Next Question";
            this.Nextquestionbutton2.UseVisualStyleBackColor = false;
            this.Nextquestionbutton2.Click += new System.EventHandler(this.Nextquestionbutton2_Click);
            // 
            // TCPtimer
            // 
            this.TCPtimer.Enabled = true;
            this.TCPtimer.Interval = 1000;
            this.TCPtimer.Tick += new System.EventHandler(this.TCPtimer_Tick);
            // 
            // ServerChecktimer
            // 
            this.ServerChecktimer.Enabled = true;
            this.ServerChecktimer.Interval = 10000;
            this.ServerChecktimer.Tick += new System.EventHandler(this.ServerChecktimer_Tick);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Dock = System.Windows.Forms.DockStyle.Left;
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(0, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(92, 20);
            this.label4.TabIndex = 4;
            this.label4.Text = "Paragraph3";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Dock = System.Windows.Forms.DockStyle.Left;
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(0, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(92, 20);
            this.label5.TabIndex = 5;
            this.label5.Text = "Paragraph4";
            // 
            // panel5
            // 
            this.panel5.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel5.Controls.Add(this.label2);
            this.panel5.Location = new System.Drawing.Point(14, 47);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(1252, 31);
            this.panel5.TabIndex = 6;
            // 
            // panel6
            // 
            this.panel6.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel6.Controls.Add(this.label3);
            this.panel6.Location = new System.Drawing.Point(14, 84);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(1252, 29);
            this.panel6.TabIndex = 7;
            // 
            // panel7
            // 
            this.panel7.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel7.Controls.Add(this.label4);
            this.panel7.Location = new System.Drawing.Point(14, 119);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(1252, 81);
            this.panel7.TabIndex = 8;
            // 
            // panel8
            // 
            this.panel8.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel8.Controls.Add(this.label5);
            this.panel8.Location = new System.Drawing.Point(14, 206);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(1252, 26);
            this.panel8.TabIndex = 9;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(14, 238);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(738, 712);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 10;
            this.pictureBox1.TabStop = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Dock = System.Windows.Forms.DockStyle.Left;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(0, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(916, 32);
            this.label6.TabIndex = 4;
            this.label6.Text = "Please Click On The Next Button To Continue To Terms And Conditions";
            // 
            // TandCrichTextBox
            // 
            this.TandCrichTextBox.BackColor = System.Drawing.Color.Black;
            this.TandCrichTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TandCrichTextBox.ForeColor = System.Drawing.Color.Yellow;
            this.TandCrichTextBox.Location = new System.Drawing.Point(3, 3);
            this.TandCrichTextBox.Name = "TandCrichTextBox";
            this.TandCrichTextBox.Size = new System.Drawing.Size(1268, 950);
            this.TandCrichTextBox.TabIndex = 2;
            this.TandCrichTextBox.Text = "";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Dock = System.Windows.Forms.DockStyle.Left;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(0, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(646, 32);
            this.label7.TabIndex = 4;
            this.label7.Text = "Click On The Start Test Button To Begin Your Test";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(34)))), ((int)(((byte)(56)))), ((int)(((byte)(85)))));
            this.ClientSize = new System.Drawing.Size(1282, 1299);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.tabPage4.ResumeLayout(false);
            this.panel4.ResumeLayout(false);
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.panel7.ResumeLayout(false);
            this.panel7.PerformLayout();
            this.panel8.ResumeLayout(false);
            this.panel8.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripProgressBar toolStripProgressBar;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel;
        private System.Windows.Forms.RichTextBox richTextBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button Nextbutton;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button StartTestbutton;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button Nextquestionbutton1;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Button Backbutton2;
        private System.Windows.Forms.Button Nextquestionbutton2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tCPConnectionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hTTPConnectionToolStripMenuItem;
        private System.Windows.Forms.Timer TCPtimer;
        private System.Windows.Forms.Timer ServerChecktimer;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RichTextBox TandCrichTextBox;
        private System.Windows.Forms.Label label7;
    }
}

