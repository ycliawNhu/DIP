namespace OpenCV_Test
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
        /// 修改這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.OpenCVTest = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // OpenCVTest
            // 
            this.OpenCVTest.Location = new System.Drawing.Point(77, 97);
            this.OpenCVTest.Name = "OpenCVTest";
            this.OpenCVTest.Size = new System.Drawing.Size(112, 45);
            this.OpenCVTest.TabIndex = 0;
            this.OpenCVTest.Text = "OpenCV測試";
            this.OpenCVTest.UseVisualStyleBackColor = true;
            this.OpenCVTest.Click += new System.EventHandler(this.OpenCVTest_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.OpenCVTest);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button OpenCVTest;
    }
}

