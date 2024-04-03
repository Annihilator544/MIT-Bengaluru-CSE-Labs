//1.	Program to display the addition using the windows application.
using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        int num1, num2;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            num2 = Convert.ToInt32(textBox2.Text);
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.Text= Convert.ToString( num1 + num2);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            num1 = Convert.ToInt32(textBox1.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox3.Text = Convert.ToString(num1 + num2);
        }

    }
}
