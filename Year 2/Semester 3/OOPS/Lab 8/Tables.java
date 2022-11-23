import java.io.*;
class multi extends Thread{
    int p;
    multi(int k){
        this.p=k;
    }
    public void run(){
        for (int i=1;i<=10;i++){
            System.out.println(p+" x "+i+" = "+p*i);
        }
    }
}
class Tables{
    public static void main(String[] args){
        multi T=new multi(5);
        multi T2 =new multi(7);
        T.start();
        T2.start();
    }
}