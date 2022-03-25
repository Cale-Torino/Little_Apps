namespace UserControlExample
{
    partial class TreeViewUserControlForm
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
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Node0");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Node1");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Node2");
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TreeViewUserControlForm));
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.StripLabel = new System.Windows.Forms.ToolStripLabel();
            this.treeView = new System.Windows.Forms.TreeView();
            this.panelCon = new System.Windows.Forms.Panel();
            this.toolStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip
            // 
            this.toolStrip.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.toolStrip.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StripLabel});
            this.toolStrip.Location = new System.Drawing.Point(0, 420);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(800, 30);
            this.toolStrip.TabIndex = 0;
            this.toolStrip.Text = "Ready";
            // 
            // StripLabel
            // 
            this.StripLabel.Name = "StripLabel";
            this.StripLabel.Size = new System.Drawing.Size(60, 25);
            this.StripLabel.Text = "Ready";
            // 
            // treeView
            // 
            this.treeView.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.treeView.HideSelection = false;
            this.treeView.HotTracking = true;
            this.treeView.Location = new System.Drawing.Point(12, 12);
            this.treeView.Name = "treeView";
            treeNode1.Name = "Node0";
            treeNode1.Tag = "";
            treeNode1.Text = "Node0";
            treeNode1.ToolTipText = "Node0";
            treeNode2.Name = "Node1";
            treeNode2.Text = "Node1";
            treeNode2.ToolTipText = "Node1";
            treeNode3.Name = "Node2";
            treeNode3.Text = "Node2";
            treeNode3.ToolTipText = "Node2";
            this.treeView.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3});
            this.treeView.ShowNodeToolTips = true;
            this.treeView.Size = new System.Drawing.Size(150, 404);
            this.treeView.TabIndex = 1;
            this.treeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView_AfterSelect);
            this.treeView.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.treeView_NodeMouseClick);
            // 
            // panelCon
            // 
            this.panelCon.BackColor = System.Drawing.SystemColors.ControlLight;
            this.panelCon.Location = new System.Drawing.Point(168, 12);
            this.panelCon.Name = "panelCon";
            this.panelCon.Size = new System.Drawing.Size(620, 404);
            this.panelCon.TabIndex = 2;
            // 
            // TreeViewUserControlForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panelCon);
            this.Controls.Add(this.treeView);
            this.Controls.Add(this.toolStrip);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TreeViewUserControlForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "TreeViewUserControlForm";
            this.Load += new System.EventHandler(this.TreeViewUserControlForm_Load);
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip;
        private System.Windows.Forms.ToolStripLabel StripLabel;
        private System.Windows.Forms.TreeView treeView;
        private System.Windows.Forms.Panel panelCon;
    }
}