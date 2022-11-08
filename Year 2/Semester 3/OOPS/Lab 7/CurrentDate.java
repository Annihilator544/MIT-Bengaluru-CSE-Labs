import java.util.*;
public class CurrentDate {
    int day,month,year;
    Scanner sc =new Scanner(System.in);
    void createDate(){
        System.out.println("Enter the Day: ");
        day=sc.nextInt();
        if(day>31||day<1){
            throw new ArithmeticException("Day Must lie between 1 and 31");
        }
        System.out.println("Enter the Month: ");
        month=sc.nextInt();
        if(month>12||month<1){
            throw new ArithmeticException("Month Must lie between 1 and 12");
        }
        System.out.println("Enter the Year: ");
        if(year>2022||year<0){
            throw new ArithmeticException("Year Must be less than 2022 and greater than 0");
        }
        year=sc.nextInt();
    }
    public static void main(String[]args){
        CurrentDate date=new CurrentDate();
        date.createDate();
    }

}
