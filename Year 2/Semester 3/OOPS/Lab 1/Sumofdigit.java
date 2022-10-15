import java.util.*;
public class Sumofdigit {
    static void Sum (int i){
        int sum=0;
        while(i!=0){
            sum+=(i%10);
            i=i/10;
        }
       System.out.println(sum);
    }
    public static void main (String args []){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter Number :");
        int n= sc.nextInt();sc.close();
        Sum(n);
}}
