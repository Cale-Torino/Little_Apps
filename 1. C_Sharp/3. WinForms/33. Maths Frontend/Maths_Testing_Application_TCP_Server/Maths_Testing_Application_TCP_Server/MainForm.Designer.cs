
namespace SuperSimpleTCP
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Disconnectbutton = new System.Windows.Forms.Button();
            this.MSGcomboBox = new System.Windows.Forms.ComboBox();
            this.Sendbutton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.Connectbutton = new System.Windows.Forms.Button();
            this.IPtextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.LogstextBox = new System.Windows.Forms.TextBox();
            this.listBox = new System.Windows.Forms.ListBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Disconnectbutton);
            this.groupBox1.Controls.Add(this.MSGcomboBox);
            this.groupBox1.Controls.Add(this.Sendbutton);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.Connectbutton);
            this.groupBox1.Controls.Add(this.IPtextBox);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(236, 18);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox1.Size = new System.Drawing.Size(1017, 297);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Controls";
            // 
            // Disconnectbutton
            // 
            this.Disconnectbutton.Location = new System.Drawing.Point(339, 151);
            this.Disconnectbutton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Disconnectbutton.Name = "Disconnectbutton";
            this.Disconnectbutton.Size = new System.Drawing.Size(112, 35);
            this.Disconnectbutton.TabIndex = 8;
            this.Disconnectbutton.Text = "Disconnect";
            this.Disconnectbutton.UseVisualStyleBackColor = true;
            this.Disconnectbutton.Click += new System.EventHandler(this.Disconnectbutton_Click);
            // 
            // MSGcomboBox
            // 
            this.MSGcomboBox.FormattingEnabled = true;
            this.MSGcomboBox.Items.AddRange(new object[] {
            "callGPIO",
            "callRESTART"});
            this.MSGcomboBox.Location = new System.Drawing.Point(14, 109);
            this.MSGcomboBox.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MSGcomboBox.Name = "MSGcomboBox";
            this.MSGcomboBox.Size = new System.Drawing.Size(436, 28);
            this.MSGcomboBox.TabIndex = 7;
            // 
            // Sendbutton
            // 
            this.Sendbutton.Location = new System.Drawing.Point(96, 151);
            this.Sendbutton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Sendbutton.Name = "Sendbutton";
            this.Sendbutton.Size = new System.Drawing.Size(112, 35);
            this.Sendbutton.TabIndex = 5;
            this.Sendbutton.Text = "Send";
            this.Sendbutton.UseVisualStyleBackColor = true;
            this.Sendbutton.Click += new System.EventHandler(this.Sendbutton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 85);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "Message";
            // 
            // Connectbutton
            // 
            this.Connectbutton.Location = new System.Drawing.Point(218, 151);
            this.Connectbutton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Connectbutton.Name = "Connectbutton";
            this.Connectbutton.Size = new System.Drawing.Size(112, 35);
            this.Connectbutton.TabIndex = 2;
            this.Connectbutton.Text = "Connect";
            this.Connectbutton.UseVisualStyleBackColor = true;
            this.Connectbutton.Click += new System.EventHandler(this.Connectbutton_Click);
            // 
            // IPtextBox
            // 
            this.IPtextBox.Location = new System.Drawing.Point(14, 49);
            this.IPtextBox.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.IPtextBox.Name = "IPtextBox";
            this.IPtextBox.Size = new System.Drawing.Size(436, 26);
            this.IPtextBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 25);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(24, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "IP";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.LogstextBox);
            this.groupBox2.Location = new System.Drawing.Point(236, 325);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox2.Size = new System.Drawing.Size(1017, 288);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Logs";
            // 
            // LogstextBox
            // 
            this.LogstextBox.BackColor = System.Drawing.Color.Black;
            this.LogstextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LogstextBox.ForeColor = System.Drawing.Color.White;
            this.LogstextBox.HideSelection = false;
            this.LogstextBox.Location = new System.Drawing.Point(4, 24);
            this.LogstextBox.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.LogstextBox.Multiline = true;
            this.LogstextBox.Name = "LogstextBox";
            this.LogstextBox.ReadOnly = true;
            this.LogstextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.LogstextBox.Size = new System.Drawing.Size(1009, 259);
            this.LogstextBox.TabIndex = 0;
            // 
            // listBox
            // 
            this.listBox.BackColor = System.Drawing.Color.Black;
            this.listBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBox.ForeColor = System.Drawing.Color.White;
            this.listBox.FormattingEnabled = true;
            this.listBox.ItemHeight = 20;
            this.listBox.Location = new System.Drawing.Point(4, 24);
            this.listBox.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.listBox.Name = "listBox";
            this.listBox.Size = new System.Drawing.Size(205, 565);
            this.listBox.TabIndex = 6;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.listBox);
            this.groupBox3.Location = new System.Drawing.Point(18, 18);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.groupBox3.Size = new System.Drawing.Size(213, 594);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Connected Clients";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1270, 631);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Maths_Testing_Application_TCP_Server";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button Sendbutton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Connectbutton;
        private System.Windows.Forms.TextBox IPtextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox LogstextBox;
        private System.Windows.Forms.ListBox listBox;
        private System.Windows.Forms.ComboBox MSGcomboBox;
        private System.Windows.Forms.Button Disconnectbutton;
        private System.Windows.Forms.GroupBox groupBox3;
    }
}

