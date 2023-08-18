import java.util.*;
public class Program012 {
  static void printDups(String str)
  {
    Map<Character, Integer> count = new HashMap<>();
    for (int i = 0; i < str.length(); i++) {
      if(count.containsKey(str.charAt(i)))
        count.put(str.charAt(i) , count.get(str.charAt(i))+1);
      else count.put(str.charAt(i),1);
    }
 
    for (Map.Entry<Character,Integer> mapElement : count.entrySet()) { 
      if (mapElement.getValue() > 1) 
        System.out.println(mapElement.getKey() + ", count = " + mapElement.getValue());
    }
  }
  public static void main(String args[])
  {
    System.out.println("enter string: ");
    Scanner sc =new Scanner(System.in);
    String str = sc.nextLine();
    sc.close();
    long begin =System.currentTimeMillis();
    printDups(str);
    long end = System.currentTimeMillis();
    System.out.println("\n"+(end-begin)+"ms");
  }
}
