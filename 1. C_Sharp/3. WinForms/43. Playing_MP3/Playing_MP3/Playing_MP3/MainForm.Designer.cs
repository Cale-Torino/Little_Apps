namespace Playing_MP3
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
            this.Playbutton = new System.Windows.Forms.Button();
            this.Stopbutton = new System.Windows.Forms.Button();
            this.label = new System.Windows.Forms.Label();
            this.Statusbutton = new System.Windows.Forms.Button();
            this.PlayOncebutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Playbutton
            // 
            this.Playbutton.Location = new System.Drawing.Point(12, 12);
            this.Playbutton.Name = "Playbutton";
            this.Playbutton.Size = new System.Drawing.Size(126, 34);
            this.Playbutton.TabIndex = 0;
            this.Playbutton.Text = "Play Loop";
            this.Playbutton.UseVisualStyleBackColor = true;
            this.Playbutton.Click += new System.EventHandler(this.Playbutton_Click);
            // 
            // Stopbutton
            // 
            this.Stopbutton.Location = new System.Drawing.Point(152, 12);
            this.Stopbutton.Name = "Stopbutton";
            this.Stopbutton.Size = new System.Drawing.Size(126, 34);
            this.Stopbutton.TabIndex = 1;
            this.Stopbutton.Text = "Stop";
            this.Stopbutton.UseVisualStyleBackColor = true;
            this.Stopbutton.Click += new System.EventHandler(this.Stopbutton_Click);
            // 
            // label
            // 
            this.label.AutoSize = true;
            this.label.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label.Location = new System.Drawing.Point(0, 100);
            this.label.Name = "label";
            this.label.Size = new System.Drawing.Size(21, 20);
            this.label.TabIndex = 2;
            this.label.Text = "R";
            // 
            // Statusbutton
            // 
            this.Statusbutton.Location = new System.Drawing.Point(152, 52);
            this.Statusbutton.Name = "Statusbutton";
            this.Statusbutton.Size = new System.Drawing.Size(126, 34);
            this.Statusbutton.TabIndex = 3;
            this.Statusbutton.Text = "Status";
            this.Statusbutton.UseVisualStyleBackColor = true;
            this.Statusbutton.Click += new System.EventHandler(this.Statusbutton_Click);
            // 
            // PlayOncebutton
            // 
            this.PlayOncebutton.Location = new System.Drawing.Point(12, 52);
            this.PlayOncebutton.Name = "PlayOncebutton";
            this.PlayOncebutton.Size = new System.Drawing.Size(126, 34);
            this.PlayOncebutton.TabIndex = 4;
            this.PlayOncebutton.Text = "Play Once";
            this.PlayOncebutton.UseVisualStyleBackColor = true;
            this.PlayOncebutton.Click += new System.EventHandler(this.PlayOncebutton_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(288, 120);
            this.Controls.Add(this.PlayOncebutton);
            this.Controls.Add(this.Statusbutton);
            this.Controls.Add(this.label);
            this.Controls.Add(this.Stopbutton);
            this.Controls.Add(this.Playbutton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Playbutton;
        private System.Windows.Forms.Button Stopbutton;
        private System.Windows.Forms.Label label;
        private System.Windows.Forms.Button Statusbutton;
        private System.Windows.Forms.Button PlayOncebutton;
    }
}

