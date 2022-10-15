/*write java program to read the values from comment line arguments
find area of rectangle
find the summation of all the values
display even and odd numbers from the given values*/
class rectangle
{	public static void main(String args[])
	{
		int l,b,a;
		l=Integer.parseInt(args[0]);
		b=Integer.parseInt(args[1]);
		a=l*b;
		System.out.println("length is "+l);
		System.out.println("breath is "+b);
		System.out.println("area of rectangle is "+a);
	}
}