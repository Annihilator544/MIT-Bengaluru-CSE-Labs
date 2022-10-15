/*write java program to read the values from comment line arguments
find area of rectangle
find the summation of all the values
display even and odd numbers from the given values*/
class evenodd
{	public static void main(String args[])
	{
		int l,i=0,j=0;
		int[] e;
		e = new int[500];
		int[] o;
		o = new int[500];

		//n=Integer.parseInt(args[0]);
		for(l=0;l<args.length;l++){
			if(Integer.parseInt(args[l])%2==0){
				e[i]=Integer.parseInt(args[l]);
				++i;
			}
			else{
				o[j]=Integer.parseInt(args[l]);
				++j;
			}
		}
		System.out.println("Even numbers are :");
		for(int k=0;k<i;k++)
			System.out.println(e[k]);
		System.out.println("Odd numbers are :");
		for(int g=0;g<j;g++)
			System.out.println(o[g]);
	}
}