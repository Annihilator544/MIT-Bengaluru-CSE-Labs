import java.util.*;

class prime
{
	public static void main(String args[])
	{
	    int q;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of prime terms you want!");
    		q=sc.nextInt();sc.close();
    		System.out.println("First "+q+" prime numbers are :-"); 
            Isprime(q);
        		
    		}
    		static void Isprime( int n){
    		     	int  i,p,count,flag;
		p=2;
    		i=1; 
	    	while(i<=n)
    		{
        		flag=1;
        		for(count=2;count<=p-1;count++)
        		{
            			if(p%count==0)  //Will be true if p is not prime
            			{
	            			flag=0;
	            			break;      //Loop will terminate if p is not prime
            			} 	 
        		}
            		if(flag==1)
            		{
               	 		System.out.print(p+" ") ;
	            		i++;
            		}
        		p++;}
	}
}