import java.util.Scanner;

public class Program018 {
    public static void main (String[] args){
        System.out.println("Enter three Numbers: ");
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        sc.close();
        long begin = System.currentTimeMillis();
        if((A>B && A<C)||(A<B && A>C)){
            System.out.println(A);
        }
        else if((B>A && B<C)||(B<A && B>C)){
            System.out.println(B);
        }
        else{
            System.out.println(C);
        }
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
