//{ Driver Code Starts
import java.util.*;
import java.io.*;
class Program042
{
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            List<String> ans = obj.find_permutation(S);
            for( int i = 0; i < ans.size(); i++)
            {
                out.print(ans.get(i)+" ");
            }
            out.println();
                        
        }
        out.close();
	}
}


// } Driver Code Ends


class Solution {
    public List<String> find_permutation(String S) {
        // Code here
        //only unique permutations are required
        //so we use set
        Set<String> set = new HashSet<>();
        permute(S, 0, S.length()-1, set);
        List<String> list = new ArrayList<>(set);
        Collections.sort(list);
        return list;
    }
    public void permute(String str, int l, int r, Set<String> set)
    {
        if(l==r)
        {
            set.add(str);
        }
        else
        {
            for(int i=l; i<=r; i++)
            {
                str = swap(str, l, i);
                permute(str, l+1, r, set);
                str = swap(str, l, i);
            }
        }
    }
    public String swap(String str, int i, int j)
    {
        char temp;
        char[] charArray = str.toCharArray();
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }
   
}
