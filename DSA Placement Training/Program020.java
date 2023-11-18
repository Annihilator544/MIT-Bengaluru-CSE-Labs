public class Program020 {
    long maxSubarraySum(int arr[], int n){
        
        // Your code here
         int size = n;
        long max_so_far = Integer.MIN_VALUE, max_ending_here
                                            = 0;
 
        for (int i = 0; i < size; i++) {
            max_ending_here = max_ending_here + arr[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    public static void main(String[] args){
        int arr[]={1,2,3,-2,5};
        int n=arr.length;
        long begin = System.nanoTime();
        Program020 obj=new Program020();
        System.out.println(obj.maxSubarraySum(arr, n));
        long end = System.nanoTime();
        System.out.println(end - begin + "ns");
    }
}
