import java.util.*;
import java.text.*;
class Number{
    public static void main(String[] args) {
 
        DecimalFormat df=new DecimalFormat("#,###.00");
        System.out.println("Enter Number : ");
        Scanner sc=new Scanner(System.in);
        double d=sc.nextDouble();
        String formattedNum= df.format(d);
        System.out.println("Formatted number : "+formattedNum);
        sc.close();
    }
}