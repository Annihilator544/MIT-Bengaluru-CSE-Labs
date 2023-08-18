import java.util.Scanner;

public class Program011 {
    public static void main(String[] args){
        System.out.println("Enter String: ");
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
        long begin = System.currentTimeMillis();
        StringBuilder input1 = new StringBuilder();
        input1.append(s);
        System.out.println(s.compareTo(input1.reverse().toString()));
        long end = System.currentTimeMillis();
        System.out.println(end-begin+"ms");
    }
}
