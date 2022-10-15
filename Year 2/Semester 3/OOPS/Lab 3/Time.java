import java.util.*;
public class Time {
    int hr,min,sec;
    Scanner sc=new Scanner(System.in);
    Time(){
        hr=min=sec=00;
    }
    void display(){
        System.out.println(hr+":"+min+":"+sec);
    }
    void read(){
        System.out.println("Enter Hours : ");
        hr=sc.nextInt();
        System.out.println("Enter Minutes : ");
        min=sc.nextInt();
        System.out.println("Enter Seconds : ");
        sec=sc.nextInt();
    }
    Time(int i,int j,int k){
        hr=i;
        sec=k;
        min=j;
    }
    static void add(Time T1,Time T2){
        int hrs,mins,secs;
        secs=(T1.sec+T2.sec);
        mins=(T1.min+T2.min)+secs/60;
        hrs=(T1.hr+T2.hr)+mins/60;
        Time T3=new Time(hrs%24,mins%60,secs%60);
        System.out.println("Sum Of Time is : ");
        T3.display();
    }
    static void Substract(Time T1,Time T2){
        Time T3=new Time(T1.hr-T2.hr,T1.min-T2.min,T1.sec-T2.sec);
        System.out.println("Difference Of Time is : ");
        T3.display();
    }
    public static void main(String[] args){
        Time T1=new Time();
        Time T2 =new Time();
        T1.read();
        T2.read();
        add(T1,T2);
        Substract(T1,T2);
    }
}

