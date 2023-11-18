public class Program027 {
    public String countAndSay(int n) {
        //leetcode 38
        //https://leetcode.com/problems/count-and-say/
        //
        if(n==1)
            return "1";
        String s=countAndSay(n-1);
        StringBuilder sb=new StringBuilder();
        int count=1;
        for(int i=1;i<s.length();i++)
        {
            if(s.charAt(i)==s.charAt(i-1))
                count++;
            else
            {
                sb.append(count);
                sb.append(s.charAt(i-1));
                count=1;
            }
        }
        sb.append(count);
        sb.append(s.charAt(s.length()-1));
        return sb.toString();   
    }
}
