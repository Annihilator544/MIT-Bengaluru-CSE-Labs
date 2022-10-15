//Create  the  equivalent  of  a  four-function  calculator
import java.util.*;
class Calculator {
    public static void main(String[] args) {
	char d;
	do{
        System.out.println("Enter first number, operator, second number: ");
        Scanner n=new Scanner(System.in);
        int a=n.nextInt();
        char b =n.next().charAt(0);
        int c=n.nextInt();
        n.close();
        switch(b){
            case '+':
                System.out.println("Answer : "+ (a+c));
                break;
            case '-':
                System.out.println("Answer : "+ (a-c));
                break;
            case '*':
                System.out.println("Answer : "+ (a*c));
                break;
            case '/':
                System.out.println("Answer : "+ (double)(a/c));
                break;}
	System.out.println("Do you wanna try again (y/n) ? ");
	d =n.next().charAt(0);
        }while(d=='y');
    }
}