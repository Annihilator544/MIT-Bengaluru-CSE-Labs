/*Write a Java program to read an int number, double number and  a char from keyboard 
 and  perform  the following  conversions:-int  to  byte,  char  to  int, double to byte, double to int*/
import java.util.*;
class Conversion {
    public static void main(String[] args) {
        Scanner p = new Scanner(System.in);
        System.out.println("Enter Integer");
        int a=p.nextInt();
        System.out.println("Enter Double");
        double b=p.nextDouble();
        System.out.println("Enter Char\n");
        char c=p.next().charAt(0);
        System.out.println("Integer to Byte : "+ (byte)a);
        System.out.println("char to Integer : " + (int)c);
        System.out.println("double to byte : "+ (byte)b);
        System.out.println("double to int : "+ (int)b);
        p.close();
    }
}