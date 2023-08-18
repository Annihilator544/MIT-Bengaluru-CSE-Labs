import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Program002 {
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
        sc.close();
        long begin =System.currentTimeMillis();
        System.out.println(Collections.max(a));
        System.out.println(Collections.min(a));
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
