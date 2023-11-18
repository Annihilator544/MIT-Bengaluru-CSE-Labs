import java.util.*;
public class Program021 {
    static int minJumps(int[] arr, int n , int k){
        // your code here
        Arrays.sort(arr);
     int ans=arr[n-1]-arr[0];
     int small=arr[0]+k;
     int large=arr[n-1]-k;
     for(int i=0;i<n-1;i++){
         int mi=Math.min(small,arr[i+1]-k);
         int ma=Math.max(large,arr[i]+k);
         if(mi<0)
         continue;
         ans=Math.min(ans,ma-mi);
    }
    return ans;
    }
    public static void main(String[] args){
        int arr[]={2,3,1,1,2,4,2,0,1,1};
        long begin = System.nanoTime();
        System.out.println(minJumps(arr, arr.length, 2));
        long end = System.nanoTime();
        System.out.println(end - begin + "ns");
    }
}
