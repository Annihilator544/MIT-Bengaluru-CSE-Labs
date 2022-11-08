import java.util.*;
public class ByTwos implements Series {
   static Scanner sc=new Scanner(System.in);
    int num;
    public void SetStart(){
        System.out.println("Enter The Number to Start with : ");
        num=sc.nextInt();
    }
    public void reset(){
        SetStart();
    }
    public int GetNext(){
        num+=2;
        return num;
    }
    public static void main(String[] args){
        ByTwos series =new ByTwos();
        int choice;
        do{
            System.out.print("Enter Choice\n1.SetStart\n2.reset\3.exit");
            System.out.println("Enter choice");
            choice=sc.nextInt();
            switch(choice){
                case 1:
                    series.SetStart();
                    int i=0;
                    while(i<10){
                        System.out.println(series.GetNext());
                        i++;
                    }
                break;
                case 2:
                    series.reset();
                    i=0;
                    while(i<10){
                        System.out.println(series.GetNext());
                        i++;
                    }
                break;
            }
        }
        while(choice!=3);

    }
}
interface Series{
    int GetNext();
    void reset();
    void SetStart();
} 