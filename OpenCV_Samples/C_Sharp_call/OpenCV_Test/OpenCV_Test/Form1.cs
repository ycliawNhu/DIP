using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace OpenCV_Test
{
    public partial class Form1 : Form
    {
        [DllImport("OpenCV_MeanFilter.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        static extern void MeanFilter(string filename, Int32 MaskSize);

        public Form1()
        {
            InitializeComponent();
        }

        private void OpenCVTest_Click(object sender, EventArgs e)
        {
            MeanFilter("Sample.bmp", 5);
        }
    }
}
