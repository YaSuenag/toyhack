namespace ToyHack
{
    partial class MinityraConsole
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
            this.label1 = new System.Windows.Forms.Label();
            this.JudenchiSocket = new System.Windows.Forms.ComboBox();
            this.GabuButton = new System.Windows.Forms.Button();
            this.Dock = new System.Windows.Forms.Button();
            this.Trigger = new System.Windows.Forms.Button();
            this.SideSwitch = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.Mode = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "獣電池";
            // 
            // JudenchiSocket
            // 
            this.JudenchiSocket.FormattingEnabled = true;
            this.JudenchiSocket.Location = new System.Drawing.Point(59, 14);
            this.JudenchiSocket.Name = "JudenchiSocket";
            this.JudenchiSocket.Size = new System.Drawing.Size(121, 20);
            this.JudenchiSocket.TabIndex = 0;
            this.JudenchiSocket.SelectedIndexChanged += new System.EventHandler(this.JudenchiSocket_SelectedIndexChanged);
            // 
            // GabuButton
            // 
            this.GabuButton.Location = new System.Drawing.Point(199, 12);
            this.GabuButton.Name = "GabuButton";
            this.GabuButton.Size = new System.Drawing.Size(75, 23);
            this.GabuButton.TabIndex = 2;
            this.GabuButton.Text = "ガブガブ";
            this.GabuButton.UseVisualStyleBackColor = true;
            this.GabuButton.Click += new System.EventHandler(this.GabuButton_Click);
            // 
            // Dock
            // 
            this.Dock.Location = new System.Drawing.Point(199, 46);
            this.Dock.Name = "Dock";
            this.Dock.Size = new System.Drawing.Size(75, 23);
            this.Dock.TabIndex = 4;
            this.Dock.Text = "合体";
            this.Dock.UseVisualStyleBackColor = true;
            this.Dock.Click += new System.EventHandler(this.Dock_Click);
            // 
            // Trigger
            // 
            this.Trigger.Location = new System.Drawing.Point(288, 12);
            this.Trigger.Name = "Trigger";
            this.Trigger.Size = new System.Drawing.Size(75, 23);
            this.Trigger.TabIndex = 3;
            this.Trigger.Text = "トリガー";
            this.Trigger.UseVisualStyleBackColor = true;
            this.Trigger.Click += new System.EventHandler(this.Trigger_Click);
            // 
            // SideSwitch
            // 
            this.SideSwitch.Location = new System.Drawing.Point(288, 46);
            this.SideSwitch.Name = "SideSwitch";
            this.SideSwitch.Size = new System.Drawing.Size(75, 23);
            this.SideSwitch.TabIndex = 5;
            this.SideSwitch.Text = "横スイッチ";
            this.SideSwitch.UseVisualStyleBackColor = true;
            this.SideSwitch.Click += new System.EventHandler(this.SideSwitch_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "モード";
            // 
            // Mode
            // 
            this.Mode.FormattingEnabled = true;
            this.Mode.Items.AddRange(new object[] {
            "オーバーチャージ",
            "カーニバル"});
            this.Mode.Location = new System.Drawing.Point(59, 48);
            this.Mode.Name = "Mode";
            this.Mode.Size = new System.Drawing.Size(121, 20);
            this.Mode.TabIndex = 1;
            this.Mode.SelectedIndexChanged += new System.EventHandler(this.Mode_SelectedIndexChanged);
            // 
            // MinityraConsole
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(375, 82);
            this.Controls.Add(this.Mode);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.SideSwitch);
            this.Controls.Add(this.Trigger);
            this.Controls.Add(this.Dock);
            this.Controls.Add(this.GabuButton);
            this.Controls.Add(this.JudenchiSocket);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MinityraConsole";
            this.Text = "ミニティラ";
            this.Load += new System.EventHandler(this.MinityraConsole_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox JudenchiSocket;
        private System.Windows.Forms.Button GabuButton;
        private System.Windows.Forms.Button Dock;
        private System.Windows.Forms.Button Trigger;
        private System.Windows.Forms.Button SideSwitch;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox Mode;
    }
}