import java.util.Scanner;

public class Program017 {
    public static void main(String[] args){
        System.out.println("Enter the Number: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        long begin = System.currentTimeMillis();
        double root= (double) Math.sqrt(n);
        if(root==Math.floor(root)){
            System.out.println(root-1);
        }
        else{
            System.out.println(Math.floor(root));
        }
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
