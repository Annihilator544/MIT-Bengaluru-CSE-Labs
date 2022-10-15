/*Write  a  Java  program  to  multiply  and  divide  a  number  by  2  using  bitwise operator.
 [Hint: use left shift and right shift bitwise operators]*/
import java.util.*;
class Bitwise {
    public static void main(String[] args) {
        System.out.println("Enter Number : ");
        Scanner n=new Scanner(System.in);
        int p=n.nextInt();n.close();
        int mul = p<<1;
        int div = p>>1;
        System.out.println("Multiplication by 2 = "+ mul);
        System.out.println("Division by 2 = "+ div);
    }
}