
namespace Steganography
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
            this.Mergebutton = new System.Windows.Forms.Button();
            this.Extractbutton = new System.Windows.Forms.Button();
            this.Browsebutton = new System.Windows.Forms.Button();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.StatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.textBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Mergebutton
            // 
            this.Mergebutton.Location = new System.Drawing.Point(12, 281);
            this.Mergebutton.Name = "Mergebutton";
            this.Mergebutton.Size = new System.Drawing.Size(75, 23);
            this.Mergebutton.TabIndex = 0;
            this.Mergebutton.Text = "Merge";
            this.Mergebutton.UseVisualStyleBackColor = true;
            this.Mergebutton.Click += new System.EventHandler(this.Mergebutton_Click);
            // 
            // Extractbutton
            // 
            this.Extractbutton.Location = new System.Drawing.Point(93, 281);
            this.Extractbutton.Name = "Extractbutton";
            this.Extractbutton.Size = new System.Drawing.Size(75, 23);
            this.Extractbutton.TabIndex = 1;
            this.Extractbutton.Text = "Extract";
            this.Extractbutton.UseVisualStyleBackColor = true;
            this.Extractbutton.Click += new System.EventHandler(this.Extractbutton_Click);
            // 
            // Browsebutton
            // 
            this.Browsebutton.Location = new System.Drawing.Point(12, 12);
            this.Browsebutton.Name = "Browsebutton";
            this.Browsebutton.Size = new System.Drawing.Size(75, 23);
            this.Browsebutton.TabIndex = 3;
            this.Browsebutton.Text = "Browse";
            this.Browsebutton.UseVisualStyleBackColor = true;
            this.Browsebutton.Click += new System.EventHandler(this.Browsebutton_Click);
            // 
            // pictureBox
            // 
            this.pictureBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.pictureBox.Location = new System.Drawing.Point(12, 41);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(276, 234);
            this.pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox.TabIndex = 4;
            this.pictureBox.TabStop = false;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 316);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(300, 22);
            this.statusStrip1.TabIndex = 5;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // StatusLabel
            // 
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(67, 17);
            this.StatusLabel.Text = "StatusLabel";
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog";
            // 
            // textBox
            // 
            this.textBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBox.HideSelection = false;
            this.textBox.Location = new System.Drawing.Point(93, 15);
            this.textBox.Name = "textBox";
            this.textBox.ReadOnly = true;
            this.textBox.Size = new System.Drawing.Size(195, 20);
            this.textBox.TabIndex = 6;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(300, 338);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.pictureBox);
            this.Controls.Add(this.Browsebutton);
            this.Controls.Add(this.Extractbutton);
            this.Controls.Add(this.Mergebutton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Mergebutton;
        private System.Windows.Forms.Button Extractbutton;
        private System.Windows.Forms.Button Browsebutton;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabel;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.TextBox textBox;
    }
}

