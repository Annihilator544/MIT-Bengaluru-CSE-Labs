import java.util.*;
class Person{
    public static void main(String args[]){
        CollegeGraduate Stu=new CollegeGraduate();
        Stu.accessor();
        Stu.Accessor();
    }
}
class prson {
    Scanner sc=new Scanner(System.in);
private String Name;
private int Date;
prson(){
    Name="N/a";
    Date= 00;
}
void accessor(){
System.out.println("Enter Name : ");
Name=sc.next();
System.out.println("Enter Birthdate : ");
Date=sc.nextInt();
System.out.println("Name : " +Name);
System.out.println("BirthDate : " +Date);
}
}
class CollegeGraduate extends prson{
    private float GPA;
    private int Year;
    CollegeGraduate(){
        GPA=0;
        Year= 0000;
    }
    void Accessor(){
        System.out.println("Enter GPA : ");
        GPA=sc.nextFloat();
        System.out.println("Enter Graduation Year : ");
        Year=sc.nextInt();
        System.out.println("Name : " +GPA);
        System.out.println("BirthDate : " +Year);
    }
}


