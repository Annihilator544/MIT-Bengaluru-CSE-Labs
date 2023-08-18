import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Program009 {
    public static void main(String[] args){
        ArrayList<Integer> a=new ArrayList<>();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number of elements in the array");
        int x=sc.nextInt();
        while(x>0){
            int p=sc.nextInt();
            a.add(p);
            x--;
        }
        sc.close();
        long begin =System.currentTimeMillis();
        Collections.rotate(a, 1);
        System.out.println(a);
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
