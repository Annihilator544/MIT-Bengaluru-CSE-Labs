import java.util.*;
class Quadritic{
    public static void main(String[] args){
        Scanner num =new Scanner(System.in);
        int a,b,c,cas;
        System.out.print("Enter a : ");
        a=num.nextInt();
        System.out.print("Enter b : ");
        b=num.nextInt();
        System.out.print("Enter c : ");
        c=num.nextInt();
        num.close();
        int determinant = (b*b-4*a*c);
        if (determinant>0)
             cas=1;
        else if(determinant<0)
             cas=2;
        else 
             cas=3;
        switch(cas){
            case 1:
                System.out.println("Roots are "+((-b+Math.sqrt(determinant))/(2*a))+" and "+((-b-Math.sqrt(determinant))/(2*a)));
                break;
            case 2 :
                int real = -b / (2 * a);
                int imaginary = (int)Math.sqrt(-determinant) / (2 * a);
                System.out.println("root1 = "+real+" + "+ imaginary+"i");
                System.out.println("root1 = "+real+" - "+ imaginary+"i");
                break;
            case 3 :
               System.out.println("Roots are "+b/(2*a)+" AND "+ b/(2*a));
               break;
        }
    }
}