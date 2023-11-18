
import java.util.*;

class Program032
{
    public static void main(String args[])
    {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            
            while(t-- > 0)
            {
                int n =sc.nextInt();
                int arr[] = new int[n];
                
                for(int i = 0; i < n; i++)
                 arr[i] = sc.nextInt();
                 
               System.out.println(new Solution().majorityElement(arr, n)); 
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int majorityElement(int a[], int size)
    {
        // your code here
        int count=0;
        int element=0;
        for(int i=0;i<size;i++){//Moore's Voting Algorithm
            if(count==0){
                element=a[i];
                count++;
            }
            else if(element==a[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<size;i++){
            if(a[i]==element){
                count++;
            }
        }
        if(count>size/2){
            return element;
        }
        else{
            return -1;
        }
    }
}