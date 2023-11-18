import java.util.*;

class Program037
{
	public static void main(String args[])
	{
		try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            while(t > 0)
            {
            	int n = sc.nextInt();
            	int m = sc.nextInt();
            	int arr[][] = new int[n][m];
            	for(int i=0; i<n; i++)
            	{
            		for(int j=0; j<m; j++ )
            		{
            			arr[i][j] = sc.nextInt();
            		}
            	}
            	System.out.println(new Solution().maxArea(arr, n, m));
            t--;
            }
        }
	}
}
// } Driver Code Ends


/*Complete the function given below*/
class Solution {
    public int maxArea(int M[][], int n, int m) {
        // add code here.
        int max = 0;
        int temp[][] = new int[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++ )
            {
                if(i==0)
                {
                    temp[i][j] = M[i][j];
                }
                else
                {
                    if(M[i][j] == 1)
                    {
                        temp[i][j] = temp[i-1][j] + 1;
                    }
                    else
                    {
                        temp[i][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            //int max1 = maxArea(temp[i], m);//aletrnate way to call maxArea function 
            int max1 = maxArea(temp[i], m);
            if(max1 > max)
            {
                max = max1;
            }
        }
        return max;
    }
    static int maxArea(int arr[], int m){
        //complete function from error line in above code
        int max = 0;
        int area = 0;
        int i = 0;
        Stack<Integer> s = new Stack<>();
        while(i < m)
        {
            if(s.empty() || arr[s.peek()] <= arr[i])
            {
                s.push(i++);
            }
            else
            {
                int top = s.peek();
                s.pop();
                if(s.empty())
                {
                    area = arr[top] * i;
                }
                else
                {
                    area = arr[top] * (i - s.peek() - 1);
                }
                if(area > max)
                {
                    max = area;
                }
            }
        }
        while(!s.empty())
        {
            int top = s.peek();
            s.pop();
            if(s.empty())
            {
                area = arr[top] * i;
            }
            else
            {
                area = arr[top] * (i - s.peek() - 1);
            }
            if(area > max)
            {
                max = area;
            }
        }
        return max;
    } 
}