import java.util.*;
class ISBN{
    public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter ISBN Number : ");
    int n=sc.nextInt();
    sc.close();
    int sum=0,count=0;
    
    for(int i=10;n!=0;i--){
        sum+=i*(n%10);
        n=n/10;
        count++;
    }
    if(count!=10){
        System.out.println("ISBN should be a 10 digit number");
    }
    else if (count ==10){
        if(sum%11==0)
            System.out.println("Legal ISBN");
        else
            System.out.println("Illegal ISBN");
    }
    }
}