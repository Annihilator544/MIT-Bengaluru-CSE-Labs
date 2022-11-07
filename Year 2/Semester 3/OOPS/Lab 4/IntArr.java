import java.util.*;
public class IntArr {
    int[] arr=new int[5];
    IntArr(){
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    void display(){
        for(int i=0;i<5;i++){
            System.out.println(arr[i]);
        }
    }
    void search(int j){
        for(int i=0;i<5;i++){
            if(j==arr[i])
            System.out.println("item found at position: "+i);
        }
    }
    static void compare(IntArr a,IntArr b){
        int flag=0;
        for(int i=0;i<5;i++){
            if(a.arr[i]!=b.arr[i]){
                flag=1;
            }
        }
        if(flag==0)
            System.out.println("arr are same");
        else
            System.out.println("arr are not same");
    }
    public static void main(String[] args){
        IntArr array=new IntArr();
        IntArr array1=new IntArr();
        array.display();
        array.search(0);
        compare(array,array1);
    }
}
