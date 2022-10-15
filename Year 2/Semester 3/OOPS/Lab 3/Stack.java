import java.util.*;
public class Stack {
    static int arr[]=new int[5];
 //  arr[0]=0;arr[1]=0;arr[2]=4;
       static int top=-1;
    static Scanner sc =new Scanner(System.in);
    void push(){
        int i;
        if(top==5){
            System.out.println("Stack Overflow");
            return;
        }
        System.out.println("Enter The Element : ");
        i=sc.nextInt();
        ++top;
        arr[top]=i;
    }
    void pop(){
        if(top==-1){
            System.out.println("Stack Underflow");
            return;
        }
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
            ob.push();
            break;
            case 2:
            ob.pop();
            break;
            case 3:
            ob.display();
            break;
        }
    }
    }
}
