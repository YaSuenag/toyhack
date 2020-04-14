﻿namespace ToyHack
{
    partial class YokaiWatchConsole
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
            this.medalList = new System.Windows.Forms.ListView();
            this.medalCategoryMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.normalMedalMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.zMedalMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.medalImageList = new System.Windows.Forms.ImageList(this.components);
            this.medalCategoryMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // medalList
            // 
            this.medalList.ContextMenuStrip = this.medalCategoryMenu;
            this.medalList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.medalList.HideSelection = false;
            this.medalList.LargeImageList = this.medalImageList;
            this.medalList.Location = new System.Drawing.Point(0, 0);
            this.medalList.MultiSelect = false;
            this.medalList.Name = "medalList";
            this.medalList.Size = new System.Drawing.Size(565, 312);
            this.medalList.TabIndex = 0;
            this.medalList.UseCompatibleStateImageBehavior = false;
            this.medalList.SelectedIndexChanged += new System.EventHandler(this.medalList_SelectedIndexChanged);
            // 
            // medalCategoryMenu
            // 
            this.medalCategoryMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.normalMedalMenu,
            this.zMedalMenu});
            this.medalCategoryMenu.Name = "medalCategoryMenu";
            this.medalCategoryMenu.Size = new System.Drawing.Size(137, 48);
            // 
            // normalMedalMenu
            // 
            this.normalMedalMenu.Name = "normalMedalMenu";
            this.normalMedalMenu.Size = new System.Drawing.Size(136, 22);
            this.normalMedalMenu.Text = "ノーマルメダル";
            this.normalMedalMenu.Click += new System.EventHandler(this.normalMedalMenu_Click);
            // 
            // zMedalMenu
            // 
            this.zMedalMenu.Name = "zMedalMenu";
            this.zMedalMenu.Size = new System.Drawing.Size(136, 22);
            this.zMedalMenu.Text = "Zメダル";
            this.zMedalMenu.Click += new System.EventHandler(this.zMedalMenu_Click);
            // 
            // medalImageList
            // 
            this.medalImageList.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.medalImageList.ImageSize = new System.Drawing.Size(16, 16);
            this.medalImageList.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // YokaiWatchConsole
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(565, 312);
            this.Controls.Add(this.medalList);
            this.Name = "YokaiWatchConsole";
            this.Text = "妖怪ウォッチ";
            this.Load += new System.EventHandler(this.YokaiWatchConsole_Load);
            this.medalCategoryMenu.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListView medalList;
        private System.Windows.Forms.ContextMenuStrip medalCategoryMenu;
        private System.Windows.Forms.ToolStripMenuItem normalMedalMenu;
        private System.Windows.Forms.ToolStripMenuItem zMedalMenu;
        private System.Windows.Forms.ImageList medalImageList;
    }
}