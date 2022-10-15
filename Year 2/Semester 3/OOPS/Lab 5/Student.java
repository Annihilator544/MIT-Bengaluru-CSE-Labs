import java.util.*;
public class Student {
	 static int choice,i =0;
	static Scanner sc= new Scanner(System.in);
	static int Regnumb=2200;
	int Regnum;
	String Name;
	Short sem;
	float GPA;
	float CGPA;
	Student(){
		Name="nil";
		sem=1;
		GPA=(float)0.0;
		CGPA=(float)0.0;
		Regnum=++Regnumb;
	}
	Student(String a,short i,float j,float k){
		Name=a;
		sem=i;
		GPA=j;
		CGPA=k;
		Regnum=++Regnumb;
	}
	void Display() {
		System.out.println("Registration Number : "+ Regnum);
		System.out.println("Name : "+ Name);
		System.out.println("Semester : "+ sem);
		System.out.println("GPA : "+ GPA);
		System.out.println("CGPA : "+ CGPA);
	}
	void Read() {
		System.out.println("Name : ");
		Name=sc.next();
		System.out.println("Semester : ");
		sem=sc.nextShort();
		System.out.println("GPA : ");
		GPA=sc.nextFloat();
		System.out.println("CGPA : ");
		CGPA=sc.nextFloat();
	}
	static void semsort(Student stu[]) {System.out.println("**");
		for(short l=1;l<=8;l++ ) {System.out.println("***");
			int ar[];
			ar=new int[100];
			int p=0;
			for(int g=0;g<i;g++) {System.out.println("****");
			if(stu[g].sem==l) {System.out.println("*****");
				ar[p]=(int)stu[g].CGPA;
				System.out.println(ar[p]);
				p++;
			}


			}System.out.println("******");
			System.out.println(ar[0]);
			System.out.println(ar[1]);
			Arrays.sort(ar);
			System.out.println(ar[0]);
			System.out.println(ar[1]);
			System.out.println("pp*");

			for(int q=0;q<p;q++){System.out.println("22*");
				for(int g=0;g<i;g++){System.out.println("ke*");
					System.out.println(stu[g].CGPA+"  "+ar[q]);
					if((int)stu[g].CGPA==(int)ar[q]){System.out.println("@*");
						stu[g].Display();
					}
				}
			}System.out.println("***end");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student stu[] = new Student[100];
		System.out.print("1. New Student\n2. Change Student Data\n3. Display Student Info\n4. Sort by CGPA\n ");
		do {
			System.out.println("Enter Choice : ");
			choice=sc.nextInt();
			switch(choice) {
			case 1:
				stu[i]=new Student();
				stu[i].Read();
				i++;
				break;
			case 2:
				System.out.println("Enter Student registration Number : ");
				int j=sc.nextInt();
				for(int k=0;k<i;k++) {
					if(stu[k].Regnum==j) {
						stu[k].Read();
					}
				}
				break;
			case 3:
				System.out.println("Enter Student registration Number : ");
				j=sc.nextInt();
				for(int k=0;k<i;k++) {
					if(stu[k].Regnum==j) {
						stu[k].Display();
					}
				}
				break;
			case 4:
			
				semsort(stu);
				System.out.println("*");
				break;
			}
		}
		while(choice!=0);
	}

}
