import java.util.*;
class GenericList{
    public static void main(String[]args){
        ArrayList linkedList=new ArrayList<>();
        linkedList.add(35);
        linkedList.add("Hello");
        for(Object i:linkedList)
        System.out.println(i);
        ArrayList<Integer> IntegerList=new ArrayList<Integer>();
        IntegerList.add(345);
        IntegerList.add(34567);
        for(int i: IntegerList)
        System.out.println(i);
        ArrayList<Double> DoubleList=new ArrayList<Double>();
        DoubleList.add(12345.3456);
        DoubleList.add(234567.09876);
        for(double i:DoubleList)
        System.out.println(i);
    }
    
    
}