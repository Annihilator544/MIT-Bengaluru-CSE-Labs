//Create a Windows application in C# for registration form and fill the details and when you click the submit button it display the details in the message box. 
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
            MessageBox.Show(s);
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
