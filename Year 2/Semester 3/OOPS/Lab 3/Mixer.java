import java.util.*;
class Mixer{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Size Of First Array : ");
        int x=sc.nextInt();
        System.out.println("Enter Size Of Second Array : ");
        int y=sc.nextInt();
        int arr1[]=new int[x];
        int arr2[]=new int[y];
        int arr3[]=new int[x+y];
        System.out.println("Enter First Array : ");
        for(int i=0;i<x;i++){
           arr3[i]= arr1[i]=sc.nextInt();
        }
        System.out.println("Enter Second Array : ");
        for(int i=0;i<y;i++){
            arr3[x+i]=arr2[i]=sc.nextInt();
        } for(int i=0;i<y+x;i++){
            System.out.println(arr3[i]);
        }
        System.out.println("Sorted Array : ");
        java.util.Arrays.sort(arr3);
        for(int i=0;i<y+x;i++){
            System.out.println(arr3[i]);
        }
    }
}