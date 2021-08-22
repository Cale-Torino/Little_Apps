
namespace HTTPSERVER
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
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.IPBox = new System.Windows.Forms.TextBox();
            this.PortUpDown = new System.Windows.Forms.NumericUpDown();
            this.HTTPSButton = new System.Windows.Forms.RadioButton();
            this.HTTPButton = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.PortUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.Color.Black;
            this.richTextBox1.ForeColor = System.Drawing.Color.White;
            this.richTextBox1.HideSelection = false;
            this.richTextBox1.Location = new System.Drawing.Point(12, 93);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(776, 345);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(128, 40);
            this.button1.TabIndex = 1;
            this.button1.Text = "Start";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.WorkerReportsProgress = true;
            this.backgroundWorker1.WorkerSupportsCancellation = true;
            this.backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(146, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(128, 40);
            this.button2.TabIndex = 2;
            this.button2.Text = "Send Test";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(280, 12);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(128, 40);
            this.button3.TabIndex = 3;
            this.button3.Text = "Clear";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // IPBox
            // 
            this.IPBox.Location = new System.Drawing.Point(414, 19);
            this.IPBox.Name = "IPBox";
            this.IPBox.Size = new System.Drawing.Size(200, 26);
            this.IPBox.TabIndex = 4;
            // 
            // PortUpDown
            // 
            this.PortUpDown.Location = new System.Drawing.Point(620, 20);
            this.PortUpDown.Maximum = new decimal(new int[] {
            999999,
            0,
            0,
            0});
            this.PortUpDown.Name = "PortUpDown";
            this.PortUpDown.Size = new System.Drawing.Size(120, 26);
            this.PortUpDown.TabIndex = 5;
            // 
            // HTTPSButton
            // 
            this.HTTPSButton.AutoSize = true;
            this.HTTPSButton.Location = new System.Drawing.Point(12, 58);
            this.HTTPSButton.Name = "HTTPSButton";
            this.HTTPSButton.Size = new System.Drawing.Size(85, 24);
            this.HTTPSButton.TabIndex = 6;
            this.HTTPSButton.TabStop = true;
            this.HTTPSButton.Text = "HTTPS";
            this.HTTPSButton.UseVisualStyleBackColor = true;
            // 
            // HTTPButton
            // 
            this.HTTPButton.AutoSize = true;
            this.HTTPButton.Location = new System.Drawing.Point(144, 58);
            this.HTTPButton.Name = "HTTPButton";
            this.HTTPButton.Size = new System.Drawing.Size(74, 24);
            this.HTTPButton.TabIndex = 7;
            this.HTTPButton.TabStop = true;
            this.HTTPButton.Text = "HTTP";
            this.HTTPButton.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.HTTPButton);
            this.Controls.Add(this.HTTPSButton);
            this.Controls.Add(this.PortUpDown);
            this.Controls.Add(this.IPBox);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "HTTPSERVER";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PortUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button button1;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TextBox IPBox;
        private System.Windows.Forms.NumericUpDown PortUpDown;
        private System.Windows.Forms.RadioButton HTTPSButton;
        private System.Windows.Forms.RadioButton HTTPButton;
    }
}

