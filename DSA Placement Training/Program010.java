import java.util.ArrayList;
import java.util.Scanner;

public class Program010 {
    public static void main(String[] args){
        System.out.println("enter number of elements in array: ");
        Scanner sc =new Scanner(System.in);
        int x=sc.nextInt();
        ArrayList <Integer>a=new ArrayList<>();
        while(x>0){
            int p=sc.nextInt();
            a.add(p);
            x--;
        }
        sc.close();
        long begin =System.currentTimeMillis();
            for(int i=0;i<a.size();i++){
                if(a.get(i)==i+1){
                    System.out.println(a.get(i));
                }
            }
        long end = System.currentTimeMillis();
        System.out.println("\n"+(end-begin)+"ms");
    }
}
