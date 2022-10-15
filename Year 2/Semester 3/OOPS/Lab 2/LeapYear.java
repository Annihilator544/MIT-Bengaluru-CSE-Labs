/*Write a Java program to find whether a given year is leap or not using boolean data type. 
[Hint: leap year has 366 days;]
Algorithm:
if(yearis not exactly divisible by 4) then(it is a common year)
elseif(yearis not exactly divisible by 100) then(it is a leap year)
elseif(yearis not exactly divisible by 400) then(it is a common year)
else(it is a leap year)*/


import java.util.*;
class LeapYear {
    public static void main(String[] args) {
        System.out.println("Enter Year: ");
        Scanner year= new Scanner(System.in);
       int n=year.nextInt();
       year.close();
        if(n%4!=0)
            System.out.println("Common Year ");
        else if(n%4==0){
            if(n%100==0){
                    if(n%400==0)
                        System.out.println("Leap Year");
                    else
                        System.out.println("Common Year");
            }
            else
            System.out.println("Leap Year");
        }
        
    }
}