import java.util.*;
class Program050
{
    public static void main (String[] args) 
    {
        try (Scanner sc = new Scanner(System.in)) {
            long t = sc.nextLong();
            
            while(t-- > 0)
            {
                long n = sc.nextLong();
                long arr[] = new long[(int)n];
                
                for(long i = 0; i < n; i++)
                 arr[(int)i] = sc.nextLong();
                 
                System.out.println(new Solution().inversionCount(arr, n));
                
            }
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    long inversionCount(long arr[], long N)
    {
        // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
        // Your Code Here
      /*Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j. */
        //brute force approach
        //time limit exceeded
        // int count = 0;
        // for(int i=0; i<N; i++)
        // {
        //     for(int j=i+1; j<N; j++)
        //     {
        //         if(arr[i] > arr[j])
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        //optimized approach
        //merge sort
        //time complexity: O(nlogn)
        //space complexity: O(n)
        long temp[] = new long[(int)N];
        return mergeSort(arr, temp, 0, N-1);

    }
    static long mergeSort(long arr[], long temp[], long left, long right)
    {
        long mid, inv_count = 0;
        if(right > left)
        {
            mid = (right + left)/2;
            inv_count = mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid+1, right);
            inv_count += merge(arr, temp, left, mid+1, right);
        }
        return inv_count;
    }
    static long merge(long arr[], long temp[], long left, long mid, long right)
    {
        long i, j, k;
        long inv_count = 0;
        i = left;
        j = mid;
        k = left;
        while((i <= mid-1) && (j <= right))
        {
            if(arr[(int)i] <= arr[(int)j])
            {
                temp[(int)k++] = arr[(int)i++];
            }
            else
            {
                temp[(int)k++] = arr[(int)j++];
                inv_count = inv_count + (mid - i);
            }
        }
        while(i <= mid-1)
        {
            temp[(int)k++] = arr[(int)i++];
        }
        while(j <= right)
        {
            temp[(int)k++] = arr[(int)j++];
        }
        for(i=left; i<=right; i++)
        {
            arr[(int)i] = temp[(int)i];
        }
        return inv_count;
    }

}