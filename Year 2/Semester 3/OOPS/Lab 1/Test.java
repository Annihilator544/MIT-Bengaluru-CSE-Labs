/* Write a method largest to find the maximum of three numbers. Also 
write a main program to read 3 numbers and find the largest among 
them using this method.*/
import java.util.*;
class Test{
	static void Largest(int i,int j, int k){
		if(i>j&&i>k)
			System.out.println(i+" is the largest Number");
		else if(j>i&&j>k)
			System.out.println(j+" is the largest Number");
		else if(k>j&&k>i)
			System.out.println(k+" is the largest Number");
		else
			System.out.println("numbers can't be same");
		
		}
	public static void main(String[] args){
		int i,j,k;
		Scanner number=new Scanner(System.in);
		System.out.print("Enter first number : ");
		i=number.nextInt();
		System.out.print("Enter second number : ");
		j=number.nextInt();
		System.out.print("Enter third number : ");
		k=number.nextInt();
		Largest(i,j,k);
		number.close();
}}	