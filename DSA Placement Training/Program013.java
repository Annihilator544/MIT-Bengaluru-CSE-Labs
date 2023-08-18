public class Program013 {
    static boolean areRotations(String s1, String s2)
    {
        if (s1.length() != s2.length()) {
            return false;
        }
        else {
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) == s2.charAt(0)) {
                    if (s1.substring(i).equals(s2.substring(0, s1.length() - i))) {
                        if (s1.substring(0, i).equals(s2.substring(s1.length()- i)))
                            return true;
                    }
                }
            }
        }
        return false;
    }
    public static void main(String[] args)
    {
        String str1 = "AACD";
        String str2 = "ACDA";
 
        long begin = System.nanoTime();
        if (areRotations(str1, str2))
            System.out.println(
                "Strings are rotations of each other");
        else
            System.out.printf(
                "Strings are not rotations of each other");
        long end = System.nanoTime();
        System.out.println("\n"+(end-begin)+"ns");
    }
}
