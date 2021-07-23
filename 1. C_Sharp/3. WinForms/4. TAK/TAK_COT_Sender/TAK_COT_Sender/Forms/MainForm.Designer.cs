
namespace TAK_COT_Sender
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ControlsgroupBox = new System.Windows.Forms.GroupBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.LoggroupBox = new System.Windows.Forms.GroupBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.StatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.LogrichTextBox = new System.Windows.Forms.RichTextBox();
            this.Sendbutton = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.ControlsgroupBox.SuspendLayout();
            this.LoggroupBox.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(751, 33);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("aboutToolStripMenuItem.Image")));
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(102, 29);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // ControlsgroupBox
            // 
            this.ControlsgroupBox.Controls.Add(this.Sendbutton);
            this.ControlsgroupBox.ForeColor = System.Drawing.Color.White;
            this.ControlsgroupBox.Location = new System.Drawing.Point(12, 36);
            this.ControlsgroupBox.Name = "ControlsgroupBox";
            this.ControlsgroupBox.Size = new System.Drawing.Size(727, 130);
            this.ControlsgroupBox.TabIndex = 1;
            this.ControlsgroupBox.TabStop = false;
            this.ControlsgroupBox.Text = "Controls";
            // 
            // LoggroupBox
            // 
            this.LoggroupBox.Controls.Add(this.LogrichTextBox);
            this.LoggroupBox.ForeColor = System.Drawing.Color.White;
            this.LoggroupBox.Location = new System.Drawing.Point(12, 172);
            this.LoggroupBox.Name = "LoggroupBox";
            this.LoggroupBox.Size = new System.Drawing.Size(727, 357);
            this.LoggroupBox.TabIndex = 2;
            this.LoggroupBox.TabStop = false;
            this.LoggroupBox.Text = "Log";
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 532);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(751, 32);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // StatusLabel
            // 
            this.StatusLabel.BackColor = System.Drawing.Color.Transparent;
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(60, 25);
            this.StatusLabel.Text = "Ready";
            // 
            // LogrichTextBox
            // 
            this.LogrichTextBox.BackColor = System.Drawing.Color.Black;
            this.LogrichTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LogrichTextBox.ForeColor = System.Drawing.Color.White;
            this.LogrichTextBox.HideSelection = false;
            this.LogrichTextBox.Location = new System.Drawing.Point(3, 22);
            this.LogrichTextBox.Name = "LogrichTextBox";
            this.LogrichTextBox.ReadOnly = true;
            this.LogrichTextBox.Size = new System.Drawing.Size(721, 332);
            this.LogrichTextBox.TabIndex = 0;
            this.LogrichTextBox.Text = "";
            // 
            // Sendbutton
            // 
            this.Sendbutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Sendbutton.Location = new System.Drawing.Point(6, 25);
            this.Sendbutton.Name = "Sendbutton";
            this.Sendbutton.Size = new System.Drawing.Size(114, 36);
            this.Sendbutton.TabIndex = 0;
            this.Sendbutton.Text = "Send";
            this.Sendbutton.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(25)))), ((int)(((byte)(25)))));
            this.ClientSize = new System.Drawing.Size(751, 564);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.LoggroupBox);
            this.Controls.Add(this.ControlsgroupBox);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TAK COT Sender";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ControlsgroupBox.ResumeLayout(false);
            this.LoggroupBox.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.GroupBox ControlsgroupBox;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.GroupBox LoggroupBox;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabel;
        private System.Windows.Forms.RichTextBox LogrichTextBox;
        private System.Windows.Forms.Button Sendbutton;
    }
}

