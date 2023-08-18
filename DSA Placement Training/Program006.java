import java.util.Arrays;
import java.util.Scanner;

public class Program006 {
    static int arr[]=new int[500];
    public static void main (String [] args){
        System.out.println("Enter the Number Elements of array:");
        Scanner sc= new Scanner(System.in);
        int k=sc.nextInt();
        int i=0;
        while(i<k){
            arr[i]=sc.nextInt();
            i++;
        }
        long begin =System.currentTimeMillis();
        Arrays.sort(arr, 0, i);
        long end = System.currentTimeMillis();
        long time=end-begin;
        System.out.println("Time taken to sort: "+time+"ms");
        System.out.println("Enter K");
        int K=sc.nextInt();
        sc.close();
        System.out.println("Kth max Element of array: "+arr[i-K]);
        System.out.println("Kth min Element of array: "+arr[K-1]);
    }
}
