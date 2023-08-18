import java.util.ArrayList;
import java.util.Scanner;

public class Program004 {
    public static void main(String[] args){
        ArrayList <Integer> a=new ArrayList<>();
        System.out.println("enter number of elements in array: ");
        Scanner sc =new Scanner(System.in);
        int x=sc.nextInt();
        while(x>0){
            int p=sc.nextInt();
            a.add(p);
            x--;
        }
        
        System.out.println("enter number to find: ");
        int y=sc.nextInt();
        sc.close();
        long begin =System.currentTimeMillis();
        System.out.println(a.lastIndexOf(y));
        System.out.println(a.indexOf(y));
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
