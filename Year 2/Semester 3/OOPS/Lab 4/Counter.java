
public class Counter {
static int count=0;
	Counter(){
		count++;
	}
	static void showCount(){
		System.out.println(count);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Counter a=new Counter();
		Counter b=new Counter();
		Counter c=new Counter();
		Counter d=new Counter();
		Counter e=new Counter();
		showCount();
	}

}
