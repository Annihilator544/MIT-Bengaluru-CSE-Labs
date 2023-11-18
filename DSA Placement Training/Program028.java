import java.io.*;
class Program028
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.longestPalin(S));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    String longestPalin(String S){
        // code here
        int n=S.length();
        int max=1;
        int start=0;
        int low,high;
        for(int i=1;i<n;i++)
        {
            low=i-1;
            high=i;
            while(low>=0 && high<n && S.charAt(low)==S.charAt(high))
            {
                if(high-low+1>max)
                {
                    start=low;
                    max=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && S.charAt(low)==S.charAt(high))
            {
                if(high-low+1>max)
                {
                    start=low;
                    max=high-low+1;
                }
                low--;
                high++;
            }
        }
        return S.substring(start,start+max);
        
    }
}