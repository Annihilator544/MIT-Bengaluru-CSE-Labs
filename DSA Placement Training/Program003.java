import java.util.Scanner;

public class Program003 {
    public static void main(String[] args){
        System.out.println("Enter String to reverse: ");
        Scanner sc = new Scanner(System.in);
        String s= sc.nextLine();
        sc.close();
        long begin =System.currentTimeMillis();
        StringBuilder input1 = new StringBuilder();
        input1.append(s);
            System.out.println(input1.reverse());
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
