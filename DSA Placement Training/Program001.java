import java.util.*;
public class Program001 {
    public static void main (String[] args){
        ArrayList<Integer> a=new ArrayList<>();
        System.out.println("enter numbers to reverse");
        Scanner sc =new Scanner(System.in);
        int x=sc.nextInt();
        while(x>0){
            int p=sc.nextInt();
            a.add(p);
            x--;
        }
        sc.close();
        long begin = System.nanoTime();
        Collections.reverse(a);
        System.out.println(a);
        long end = System.nanoTime();
        System.out.println(end - begin + "ns");
    }
}