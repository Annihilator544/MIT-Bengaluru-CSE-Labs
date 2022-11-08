import java.util.*;

public class Student {
	 static int choice,i =0;
	static Scanner sc= new Scanner(System.in);
	static int Regnumb=2200;
	int Regnum;
	static Student stu[] = new Student[100];
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
        try{
        if(Regnum>2225){
            throw new ArithmeticException();
            }
        }catch(Exception e){
            System.out.println("All The seats in the classroom are filled.");
        }
	}
	void Display() {
		System.out.println("Registration Number : "+ Regnum);
		System.out.println("Name : "+ Name);
		System.out.println("Semester : "+ sem);
		System.out.println("GPA : "+ GPA);
		System.out.println("CGPA : "+ CGPA);
	}
	void Read() {
		System.out.print("Name : ");
		sc.nextLine();
		Name=sc.nextLine();
		System.out.println("Semester : ");
		sem=sc.nextShort();
		System.out.println("GPA : ");
		GPA=sc.nextFloat();
		System.out.println("CGPA : ");
		CGPA=sc.nextFloat();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.print("1. New Student\n2. Change Student Data\n3. Display Student Info\n4. Sort by Sem\n5. Sort by CGPA\n6. Sort by Name\n7.Search name by character\n8. Search by Middle Name\n9.Shorten Name\n");
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
			
			for(int l=1;l<=8;l++){
				for (int k=0;k<i;k++){
					if(stu[k].sem==l){
						stu[k].Display();
					}
				}
			}
				break;
			case 5:
				float ar[]=new float[100];
				for (int k=0;k<i;k++){
					ar[k]=stu[k].CGPA;
				}
				for(int k=0;k<i;k++){
					for(int t=k+1;t<i;t++){
						if(ar[k]<ar[t]){
							float temp=ar[k];
							ar[k]=ar[t];
							ar[t]=temp;
						}
					}
				}
				for(int k=0;k<i;k++){
					for(int t=0;t<i;t++){
						if(ar[k]==stu[t].CGPA){
							stu[t].Display();
						}
					}
				}
				break;
			case 6:
			String names[]=new String[100];
			for (int k=0;k<i;k++){
				names[k]=stu[k].Name;
			}
			String temp;
			for (int n = 0; n < i; n++) {
				for (int p = n + 1; p < i; p++) {
				   
					if (names[n].compareTo(names[p]) > 0) {
						temp = names[n];
						names[n] = names[p];
						names[p] = temp;
					}
				}
			}
			for(int k=0;k<i;k++){
				for(int t=0;t<i;t++){
					if(names[k]==stu[t].Name){
						stu[t].Display();
					}
				}
			}
			break;
			case 7:
			System.out.println("Enter Character to Search : ");
			char c=sc.next().charAt(0);
			for(int k=0;k<i;k++){
				if(c==stu[k].Name.charAt(0)){
					stu[k].Display();
				}
			}
			break;
			case 8:
				System.out.println("Enter String To search : ");
				String s=sc.next();
				for(int k=0;k<i;k++){
				int index = stu[k].Name.indexOf(s);
				if(index>=0){
					stu[k].Display();
				}
				}
				break;
			case 9:
			for(int k=0;k<i;k++){
			int len = stu[k].Name.length();
			stu[k].Name = stu[k].Name.trim();
			String str1 = "";
			for (int i = 0; i < len; i++) {
			   char ch = stu[k].Name.charAt(i);
			   if (ch != ' ') {
				  str1 = str1 + ch;
			   } else {
				  System.out.print(Character.toUpperCase(str1.charAt(0)) + ". ");
				  str1 = "";
			   }
			}
			String str2 = "";
			for (int p = 0; p< str1.length(); p++) {
			   if (p == 0)
				  str2 = str2 + Character.toUpperCase(str1.charAt(0));
			   else
				  str2 = str2 + Character.toLowerCase(str1.charAt(p));
			}
			System.out.println(str2);
		}
			break;

			}
		}
		while(choice!=0);
	}

}