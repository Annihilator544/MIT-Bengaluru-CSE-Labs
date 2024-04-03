//3.	Write a C# program to which reads a set of strings into the rows a two dimensional array and then prints the string having more number of vowels
using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter the number of strings: ");
        int numberOfRows = int.Parse(Console.ReadLine());

        Console.Write("Enter the maximum length of each string: ");
        int maxLength = int.Parse(Console.ReadLine());

        // Create a 2D array to store the strings
        string[,] stringsArray = new string[numberOfRows, maxLength];

        // Read strings into the array
        for (int i = 0; i < numberOfRows; i++)
        {
            Console.Write($"Enter string {i + 1}: ");
            string input = Console.ReadLine();
            for (int j = 0; j < input.Length && j < maxLength; j++)
            {
                stringsArray[i, j] = input[j].ToString();
            }
        }

        // Find string with maximum vowels
        string maxVowelString = FindStringWithMaxVowels(stringsArray);

        // Print the string with the most vowels
        Console.WriteLine("String with the most vowels:");
        Console.WriteLine(maxVowelString);
    }

    // Function to count vowels in a string
    static int CountVowels(string str)
    {
        int count = 0;
        foreach (char c in str)
        {
            if ("aeiouAEIOU".Contains(c))
                count++;
        }
        return count;
    }

    // Function to find the string with the maximum number of vowels
    static string FindStringWithMaxVowels(string[,] array)
    {
        string maxVowelString = "";
        int maxVowels = 0;

        for (int i = 0; i < array.GetLength(0); i++)
        {
            string currentString = "";
            for (int j = 0; j < array.GetLength(1); j++)
            {
                if (array[i, j] != null)
                    currentString += array[i, j];
            }
            int vowels = CountVowels(currentString);
            if (vowels > maxVowels)
            {
                maxVowels = vowels;
                maxVowelString = currentString;
            }
        }
        return maxVowelString;
    }
}
