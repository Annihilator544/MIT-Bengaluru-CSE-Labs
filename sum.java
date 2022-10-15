/*write java program to read the values from comment line arguments
find area of rectangle
find the summation of all the values
display even and odd numbers from the given values*/
class sum
{	public static void main(String args[])
	{
		int l,sum=0;
		//n=Integer.parseInt(args[0]);
		for(l=0;l<args.length;l++){
			sum+=Integer.parseInt(args[l]);
			}
		System.out.println("number of number: "+args.length);
		System.out.println("sum of numbers is "+sum);
		System.out.println(args.length);
	}
}