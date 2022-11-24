class Stack<T>{
    T t;
    public static void main(String[]args){
        Student stu=new Student();
        Employee emp=new Employee();
        Stack<Integer> intval=new Stack<Integer>();
        intval.t=5;
        stu.i=emp.i=intval.t;
        Stack<String> strval=new Stack<String>();
        strval.t="Hello";
        stu.s=emp.s=strval.t;
        System.out.println(stu.i+"\n"+stu.s);
        System.out.println(emp.i+"\n"+emp.s);
    }
}
class Student{
    int i;
    String s;
}
class Employee{
    int i;
    String s;
}