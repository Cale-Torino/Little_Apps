namespace UserControlExample
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.TreeViewbutton = new System.Windows.Forms.Button();
            this.ListViewbutton = new System.Windows.Forms.Button();
            this.Buttonsbutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TreeViewbutton
            // 
            this.TreeViewbutton.Location = new System.Drawing.Point(12, 12);
            this.TreeViewbutton.Name = "TreeViewbutton";
            this.TreeViewbutton.Size = new System.Drawing.Size(112, 34);
            this.TreeViewbutton.TabIndex = 0;
            this.TreeViewbutton.Text = "TreeView";
            this.TreeViewbutton.UseVisualStyleBackColor = true;
            this.TreeViewbutton.Click += new System.EventHandler(this.TreeViewbutton_Click);
            // 
            // ListViewbutton
            // 
            this.ListViewbutton.Location = new System.Drawing.Point(130, 12);
            this.ListViewbutton.Name = "ListViewbutton";
            this.ListViewbutton.Size = new System.Drawing.Size(112, 34);
            this.ListViewbutton.TabIndex = 1;
            this.ListViewbutton.Text = "ListView";
            this.ListViewbutton.UseVisualStyleBackColor = true;
            this.ListViewbutton.Click += new System.EventHandler(this.ListViewbutton_Click);
            // 
            // Buttonsbutton
            // 
            this.Buttonsbutton.Location = new System.Drawing.Point(248, 12);
            this.Buttonsbutton.Name = "Buttonsbutton";
            this.Buttonsbutton.Size = new System.Drawing.Size(112, 34);
            this.Buttonsbutton.TabIndex = 2;
            this.Buttonsbutton.Text = "Buttons";
            this.Buttonsbutton.UseVisualStyleBackColor = true;
            this.Buttonsbutton.Click += new System.EventHandler(this.Buttonsbutton_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(372, 61);
            this.Controls.Add(this.Buttonsbutton);
            this.Controls.Add(this.ListViewbutton);
            this.Controls.Add(this.TreeViewbutton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button TreeViewbutton;
        private System.Windows.Forms.Button ListViewbutton;
        private System.Windows.Forms.Button Buttonsbutton;
    }
}
