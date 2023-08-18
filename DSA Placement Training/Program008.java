import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Program008 {
    public static void main(String[] args){
        System.out.println("Enter number of elemnts in Array 1: ");
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        Set<Integer> a=new HashSet<>();
        while(x>0){
            int p=sc.nextInt();
            a.add(p);
            x--;
        }
        System.out.println("Enter number of elemnts in Array 2: ");
        x=sc.nextInt();
        Set<Integer> b=new HashSet<>();
        while(x>0){
            int p=sc.nextInt();
            b.add(p);
            x--;
        }
        sc.close();
        long begin =System.currentTimeMillis();
        Set<Integer> c=new HashSet<>(a);
        Set<Integer> d=new HashSet<>(a);
        c.addAll(b);
        System.out.println(c);
        d.retainAll(b);
        System.out.println(d);
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
