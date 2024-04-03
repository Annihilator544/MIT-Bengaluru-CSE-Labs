//2.	Write a C# programs to demonstrate the concepts of Label, Text Box ,radio button and Button controls.
using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        string name, gender;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            name = textBox1.Text;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked)
            {
                gender = radioButton2.Text;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string s = "hello " + name;
            label4.Text = s;
            label4.Visible = true;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                gender = radioButton1.Text;
            }
        }
    }
}
