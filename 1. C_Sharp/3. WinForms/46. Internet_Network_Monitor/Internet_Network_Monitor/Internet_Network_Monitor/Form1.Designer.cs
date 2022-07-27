namespace Internet_Network_Monitor
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
            this.networkCardLabel = new System.Windows.Forms.Label();
            this.statusLabel = new System.Windows.Forms.Label();
            this.diskDetectionCheckbox = new System.Windows.Forms.CheckBox();
            this.diskActivityLabel = new System.Windows.Forms.Label();
            this.networkSpeedLabel = new System.Windows.Forms.Label();
            this.toggleStatusLabel = new System.Windows.Forms.Label();
            this.togglebutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // networkCardLabel
            // 
            this.networkCardLabel.AutoSize = true;
            this.networkCardLabel.Location = new System.Drawing.Point(348, 9);
            this.networkCardLabel.Name = "networkCardLabel";
            this.networkCardLabel.Size = new System.Drawing.Size(138, 20);
            this.networkCardLabel.TabIndex = 0;
            this.networkCardLabel.Text = "networkCardLabel";
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Location = new System.Drawing.Point(269, 236);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(92, 20);
            this.statusLabel.TabIndex = 1;
            this.statusLabel.Text = "statusLabel";
            // 
            // diskDetectionCheckbox
            // 
            this.diskDetectionCheckbox.AutoSize = true;
            this.diskDetectionCheckbox.Location = new System.Drawing.Point(352, 72);
            this.diskDetectionCheckbox.Name = "diskDetectionCheckbox";
            this.diskDetectionCheckbox.Size = new System.Drawing.Size(202, 24);
            this.diskDetectionCheckbox.TabIndex = 2;
            this.diskDetectionCheckbox.Text = "diskDetectionCheckbox";
            this.diskDetectionCheckbox.UseVisualStyleBackColor = true;
            // 
            // diskActivityLabel
            // 
            this.diskActivityLabel.AutoSize = true;
            this.diskActivityLabel.Location = new System.Drawing.Point(348, 29);
            this.diskActivityLabel.Name = "diskActivityLabel";
            this.diskActivityLabel.Size = new System.Drawing.Size(125, 20);
            this.diskActivityLabel.TabIndex = 3;
            this.diskActivityLabel.Text = "diskActivityLabel";
            // 
            // networkSpeedLabel
            // 
            this.networkSpeedLabel.AutoSize = true;
            this.networkSpeedLabel.Location = new System.Drawing.Point(348, 49);
            this.networkSpeedLabel.Name = "networkSpeedLabel";
            this.networkSpeedLabel.Size = new System.Drawing.Size(151, 20);
            this.networkSpeedLabel.TabIndex = 4;
            this.networkSpeedLabel.Text = "networkSpeedLabel";
            // 
            // toggleStatusLabel
            // 
            this.toggleStatusLabel.AutoSize = true;
            this.toggleStatusLabel.Location = new System.Drawing.Point(367, 236);
            this.toggleStatusLabel.Name = "toggleStatusLabel";
            this.toggleStatusLabel.Size = new System.Drawing.Size(139, 20);
            this.toggleStatusLabel.TabIndex = 5;
            this.toggleStatusLabel.Text = "toggleStatusLabel";
            // 
            // togglebutton
            // 
            this.togglebutton.Location = new System.Drawing.Point(352, 102);
            this.togglebutton.Name = "togglebutton";
            this.togglebutton.Size = new System.Drawing.Size(185, 39);
            this.togglebutton.TabIndex = 6;
            this.togglebutton.Text = "Toggle Auto Shutdown";
            this.togglebutton.UseVisualStyleBackColor = true;
            this.togglebutton.Click += new System.EventHandler(this.togglebutton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.togglebutton);
            this.Controls.Add(this.toggleStatusLabel);
            this.Controls.Add(this.networkSpeedLabel);
            this.Controls.Add(this.diskActivityLabel);
            this.Controls.Add(this.diskDetectionCheckbox);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.networkCardLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label networkCardLabel;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.CheckBox diskDetectionCheckbox;
        private System.Windows.Forms.Label diskActivityLabel;
        private System.Windows.Forms.Label networkSpeedLabel;
        private System.Windows.Forms.Label toggleStatusLabel;
        private System.Windows.Forms.Button togglebutton;
    }
}

