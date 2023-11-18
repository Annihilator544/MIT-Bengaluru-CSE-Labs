//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
class Program044
{
    public static void main (String[] args)
    {
        
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            
            while(t-- > 0)
            {
                int l = sc.nextInt();
                int n = sc.nextInt();
                
                int arr[] =  new int[l];
                
                for(int i = 0;i<l;i++)
                    arr[i] = sc.nextInt();
                
                Solution ob = new Solution();
                    
                if(ob.findPair(arr, l, n)==true)
                    System.out.println(1);
                    
                else
                    System.out.println(-1);    
                    
            }
        }
        
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public boolean findPair(int arr[], int size, int n)
    {
        //code here.
        //optimized approach
        //time limit exceeded for brute force approach
        //alternate approach is to use hashing
        //but it will not work for duplicate elements
        //so we use sorting
        Arrays.sort(arr);
        int i=0, j=arr.length-1;
        while(i<j)
        {
            if(arr[j]-arr[i] == n)
            {
                return true;
            }
            else if(arr[j]-arr[i] > n)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
        
    }
}
