import java.util.*;
public class Complex {
	int real,imaginary;
Complex(){
		real=0; imaginary=0;
	}
	Complex(int tempReal, int tempImaginary)
	{
		real = tempReal;
		imaginary = tempImaginary;
	}
	Complex addComp(Complex C1, Complex C2)
	{	Complex temp = new Complex();
		temp.real = C1.real + C2.real;
		temp.imaginary = C1.imaginary + C2.imaginary;
		return temp;
	}
	Complex subtractComp(Complex C1, Complex C2)
	{	Complex temp = new Complex();
		temp.real = C1.real - C2.real;
		temp.imaginary = C1.imaginary - C2.imaginary;
		return temp;
	}
	void printComplexNumber()
	{
		System.out.println("Complex number: "+ real + " + "+ imaginary + "i");
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Real And Imaginary Part Of Number 1 :");
		int a=sc.nextInt();
		int b=sc.nextInt();
		System.out.println("Enter Real And Imaginary Part Of Number 2 :");
		int c=sc.nextInt();
		int d=sc.nextInt();
		sc.close();
		Complex C1 = new Complex(a, b);
		C1.printComplexNumber();
		Complex C2 = new Complex(c, d);
		C2.printComplexNumber();
		Complex C3 = new Complex();
		C3 = C3.addComp(C1, C2);
		System.out.print("Sum of ");
		C3.printComplexNumber();
		C3 = C3.subtractComp(C1, C2);
		System.out.print("Difference of ");
		C3.printComplexNumber();
	}

}
