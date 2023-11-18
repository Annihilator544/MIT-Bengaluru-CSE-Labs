// Java program for the above approach
import java.util.*;
class Program041 {

	// Declare a global list
	static List<String> al = new ArrayList<>();

	// Creating a public static Arraylist such that
	// we can store values
	// IF there is any question of returning the
	// we can directly return too// public static
	// ArrayList<String> al = new ArrayList<String>();
	public static void main(String[] args)
	{
		String s = "abcd";
		findsubsequences(s, ""); // Calling a function
		System.out.println(al);
	}

	private static void findsubsequences(String s,
										String ans)
	{
		if (s.length() == 0) {
			al.add(ans);
			return;
		}

		// We add adding 1st character in string
		findsubsequences(s.substring(1), ans + s.charAt(0));

		// Not adding first character of the string
		// because the concept of subsequence either
		// character will present or not
		findsubsequences(s.substring(1), ans);
	}
}
