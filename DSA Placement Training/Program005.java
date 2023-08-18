import java.util.*;

public class Program005 {
    public static void main(String[] args){
        System.out.println("enter number of elements in array: ");
        Scanner sc =new Scanner(System.in);
        int x=sc.nextInt();
        sc.close();
        int a[]=new int[x];
        int b[]=new int[3];
        b[0]=0;
        b[1]=0;
        b[2]=0;
        while(x>0){
            int p=sc.nextInt();
            a[x-1]=p;
            b[p]++;
            x--;
        } 
        long begin =System.currentTimeMillis();
        int p=0;
        for(;p<b[0];p++){
            a[p]=0;
        }
        for(;p<b[0]+b[1];p++){
            a[p]=1;
        }
        for(;p<b[0]+b[1]+b[2];p++){
            a[p]=2;
        }
        for(int i=0;i<a.length;i++){
            System.out.print(a[i]+"\t");
        }
        
        long end = System.currentTimeMillis();
        System.out.println("\n"+(end-begin)+"ms");
    }
}
