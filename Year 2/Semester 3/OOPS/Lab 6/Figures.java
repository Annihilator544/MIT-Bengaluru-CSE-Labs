abstract class Figure{
    int i=10;
    int j=20;
    int area(){
        return(i*j);
    }
}
class rectangle extends Figure{
    int area(){
        System.out.println("Printing From Rectangle : "+i*j);
        return(i*j);
    }
}
class triangle extends Figure{
    int area(){
        System.out.println("Printing From triangle : "+i*j/2);
        return(i*j/2);
    }
}
class square extends Figure{
    int area(){
        System.out.println("Printing From square : "+i*i);
        return(i*i);
    }
}
public class Figures {
    public static void main(String args[]){
        rectangle ob1=new rectangle();
        triangle ob2=new triangle();
        square ob3=new square();
        Figure ref;
        ref=ob1;
        ref.area();
        ref=ob2;
        ref.area();
        ref=ob3;
        ref.area();
    }

    
}
