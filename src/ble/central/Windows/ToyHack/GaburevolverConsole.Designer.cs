namespace ToyHack
{
    partial class GaburevolverConsole
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
            this.UpperSocket = new System.Windows.Forms.ComboBox();
            this.LowerSocket = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SetterButton = new System.Windows.Forms.Button();
            this.RotateButton = new System.Windows.Forms.Button();
            this.TriggerButton = new System.Windows.Forms.Button();
            this.MinityraButton = new System.Windows.Forms.Button();
            this.GaburicariburButton = new System.Windows.Forms.Button();
            this.JudenchiSetButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // UpperSocket
            // 
            this.UpperSocket.FormattingEnabled = true;
            this.UpperSocket.Location = new System.Drawing.Point(68, 12);
            this.UpperSocket.Name = "UpperSocket";
            this.UpperSocket.Size = new System.Drawing.Size(121, 20);
            this.UpperSocket.TabIndex = 0;
            // 
            // LowerSocket
            // 
            this.LowerSocket.FormattingEnabled = true;
            this.LowerSocket.Location = new System.Drawing.Point(68, 49);
            this.LowerSocket.Name = "LowerSocket";
            this.LowerSocket.Size = new System.Drawing.Size(121, 20);
            this.LowerSocket.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "上ソケット";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 52);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "下ソケット";
            // 
            // SetterButton
            // 
            this.SetterButton.Location = new System.Drawing.Point(206, 10);
            this.SetterButton.Name = "SetterButton";
            this.SetterButton.Size = new System.Drawing.Size(75, 23);
            this.SetterButton.TabIndex = 2;
            this.SetterButton.Text = "オープン";
            this.SetterButton.UseVisualStyleBackColor = true;
            this.SetterButton.Click += new System.EventHandler(this.SetterButton_Click);
            // 
            // RotateButton
            // 
            this.RotateButton.Location = new System.Drawing.Point(206, 47);
            this.RotateButton.Name = "RotateButton";
            this.RotateButton.Size = new System.Drawing.Size(75, 23);
            this.RotateButton.TabIndex = 4;
            this.RotateButton.Text = "回転";
            this.RotateButton.UseVisualStyleBackColor = true;
            this.RotateButton.Click += new System.EventHandler(this.RotateButton_Click);
            // 
            // TriggerButton
            // 
            this.TriggerButton.Location = new System.Drawing.Point(287, 47);
            this.TriggerButton.Name = "TriggerButton";
            this.TriggerButton.Size = new System.Drawing.Size(75, 23);
            this.TriggerButton.TabIndex = 5;
            this.TriggerButton.Text = "トリガー";
            this.TriggerButton.UseVisualStyleBackColor = true;
            this.TriggerButton.Click += new System.EventHandler(this.TriggerButton_Click);
            // 
            // MinityraButton
            // 
            this.MinityraButton.Location = new System.Drawing.Point(78, 82);
            this.MinityraButton.Name = "MinityraButton";
            this.MinityraButton.Size = new System.Drawing.Size(116, 23);
            this.MinityraButton.TabIndex = 6;
            this.MinityraButton.Text = "ミニティラ合体";
            this.MinityraButton.UseVisualStyleBackColor = true;
            this.MinityraButton.Click += new System.EventHandler(this.MinityraButton_Click);
            // 
            // GaburicariburButton
            // 
            this.GaburicariburButton.Location = new System.Drawing.Point(200, 82);
            this.GaburicariburButton.Name = "GaburicariburButton";
            this.GaburicariburButton.Size = new System.Drawing.Size(116, 23);
            this.GaburicariburButton.TabIndex = 7;
            this.GaburicariburButton.Text = "ガブリカリバー合体";
            this.GaburicariburButton.UseVisualStyleBackColor = true;
            this.GaburicariburButton.Click += new System.EventHandler(this.GaburicariburButton_Click);
            // 
            // JudenchiSetButton
            // 
            this.JudenchiSetButton.Location = new System.Drawing.Point(287, 10);
            this.JudenchiSetButton.Name = "JudenchiSetButton";
            this.JudenchiSetButton.Size = new System.Drawing.Size(75, 23);
            this.JudenchiSetButton.TabIndex = 3;
            this.JudenchiSetButton.Text = "獣電池セット";
            this.JudenchiSetButton.UseVisualStyleBackColor = true;
            this.JudenchiSetButton.Click += new System.EventHandler(this.JudenchiSetButton_Click);
            // 
            // GaburevolverConsole
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(375, 117);
            this.Controls.Add(this.JudenchiSetButton);
            this.Controls.Add(this.GaburicariburButton);
            this.Controls.Add(this.MinityraButton);
            this.Controls.Add(this.TriggerButton);
            this.Controls.Add(this.RotateButton);
            this.Controls.Add(this.SetterButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.LowerSocket);
            this.Controls.Add(this.UpperSocket);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GaburevolverConsole";
            this.Text = "ガブリボルバー";
            this.Load += new System.EventHandler(this.GaburevolverConsole_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox UpperSocket;
        private System.Windows.Forms.ComboBox LowerSocket;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button SetterButton;
        private System.Windows.Forms.Button RotateButton;
        private System.Windows.Forms.Button TriggerButton;
        private System.Windows.Forms.Button MinityraButton;
        private System.Windows.Forms.Button GaburicariburButton;
        private System.Windows.Forms.Button JudenchiSetButton;
    }
}