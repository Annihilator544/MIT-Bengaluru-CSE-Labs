import java.util.*;
public class Stack {
    static int arr[]=new int[5];
 //  arr[0]=0;arr[1]=0;arr[2]=4;
       static int top=-1;
    static Scanner sc =new Scanner(System.in);
    void push(){
        int i;
        System.out.println("Enter The Element : ");
        i=sc.nextInt();
        ++top;
        arr[top]=i;
    }
    void pop(){
        top--;
    }
    void display(){
        for (int i=0;i<=top;i++){
            System.out.print(arr[i]+ "\t");
        }

    }
    public static void main(String[] args){
        for(int j=1;j>0;j++){
        System.out.println("Enter Choice : ");
        Stack ob=new Stack();
        int choice;
        choice=sc.nextInt();

        
            
        switch(choice){
            case 1:
            try{
            ob.push();
            }
            catch(Exception e){
                System.out.println("Stack Overflow");
                System.out.println(e.getMessage());
            }
            break;
            case 2:
            try{
                ob.pop();
                }
                catch(Exception e){
                    System.out.println("Stack Underflow");
                    System.out.println(e.toString());
                }
            break;
            case 3:
            try{
                ob.display();
                }
                catch(Exception e){
                    System.out.println("No Item To Display");
                    System.out.println(e.getMessage());
                }
            break;
        }
    }
    }
}
