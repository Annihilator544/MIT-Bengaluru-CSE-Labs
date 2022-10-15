import java.util.*;
class Bank
{
    String Name;
    long AccNum;
    String Type;
    int Balance;
    static Scanner sc=new Scanner(System.in);
     Bank()
     {
        Name="N/A";
        AccNum=000000000;
        Type="N/A";
        Balance=0;
    }
    void info()
    {
        System.out.println("Enter Name ");
        Name=sc.nextLine();
        System.out.println("Enter Account Number ");
        AccNum=sc.nextLong();
        System.out.println("Enter Account Type ");
        Type=sc.nextLine();
        System.out.println("Enter Balance ");
        Balance=sc.nextInt();
    }
    void deposit()
    {
        System.out.println("Enter amount to deposit : ");
        int n=sc.nextInt();
        Balance=Balance +n;
    }
    void withdraw()
    {
        System.out.println("Enter amount to withdraw : ");
        int n=sc.nextInt();
        if((Balance-n)<0)
            System.out.println("Insufficient Balance");
        else
            Balance-=n;
    }
    void display()
    {
        System.out.println("Name : "+Name);
        System.out.println("Account Number : "+AccNum );
        System.out.println("Account Type : "+Type);
        System.out.println("Bank Balance : "+ Balance);
    }
    public static void main(String[] args)
    {
        Bank Acc=new Bank();
        int choice,i=0;
        Acc.info();
        System.out.print("1. Deposit \n2. Withdraw\n3. display\n4. exit");
        while(i==0){
        choice=sc.nextInt();
        switch(choice){
            case 1:
            Acc.deposit();
            break;
            case 2:
            Acc.withdraw();
            break;
            case 3:
            Acc.display();
            break;
            case 4:
            i=1;
            break;
            

        }
        }
    }
}