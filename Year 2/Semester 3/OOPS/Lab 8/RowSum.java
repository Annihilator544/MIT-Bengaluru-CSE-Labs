import java.util.*;
public class RowSum {
    static int q=0;
 static Scanner sc=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println("Enter Number of Rows");
        int rownum=sc.nextInt();
        for(int i=0;i<rownum;i++){
        Thread t = new Thread(new RowSum().new RunnableImpl());
        t.setPriority(1);
        t.start();
        try {             
            t.join(); 
         } catch (InterruptedException e) {
            e.printStackTrace();
         }
        }
        System.out.println("Total Matrix Sum = "+q);
    }
 
    private class RunnableImpl implements Runnable {
 
        public void run()
        {
            int row;
            int sum=0;
            System.out.println("Enter number of entries in Row ");
            row= sc.nextInt();
            int arr[]=new int[row];
            System.out.println("Enter The Elements : ");
            for(int i=0;i<row;i++){
                arr[i]=sc.nextInt();
                sum+=arr[i];
            }
            System.out.println("Row Sum = "+  sum);
            q+=sum;
        }
    }
}