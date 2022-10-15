import java.util.*;
class Armstrong {
static boolean Arm (int i){
    int num=i;
    int sum=0;
    while(i!=0){
        sum+=(i%10)*(i%10)*(i%10);
        i=i/10;
    }
    if(sum==num){
        return (true);
    }
    else
    return(false);
}
public static void main (String args []){
Scanner sc =new Scanner(System.in);
System.out.println("Enter Number :");
int n= sc.nextInt();sc.close();
if(Arm(n)){
    System.out.println("Armsteong Number ");
}
else{
    System.out.println(" not a Armsteong Number ");
}
}
}