import javax.crypto.AEADBadTagException;

public class Customer {
    private 
    int CSTDID;
    String Name;
    int CredLimit;
    public
    Customer(){
        CSTDID=0;
        Name="n/a";
        CredLimit=0;
    }
    Customer(int i, String s, int j){
        CSTDID=i;
        Name=s;
        CredLimit=j;
    }
    void Display(){
        System.out.println(CSTDID);
        System.out.println(Name);
        System.out.println(CredLimit);
    }
    public static void main(String[] args){
        Customer cus[]=new Customer[5];
        cus[0]= new Customer(2, "AEADB", 0);
        cus[1]= new Customer(3, "AEDB", 1);
        cus[2]= new Customer(4, "AEB", 2);
        cus[3]= new Customer(5, "AB", 3);
        cus[4]= new Customer(6, "A", 4);
        for(int i=0;i<5;i++){
            cus[i].Display();
        }
        
    } 
}
