import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Program007 {
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
        long begin =System.currentTimeMillis();
        int low=0;
        int high=a.size()-1;
        while(low<high){
            if(a.get(low)<=0){
                low++;
                System.out.println(a);
            }
            else{
                Collections.swap(a, low, high--);
                System.out.println(a);
            }
        }
        sc.close();
        System.out.println(a);
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
