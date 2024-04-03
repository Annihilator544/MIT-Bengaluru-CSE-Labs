//2.	Write a C# program to display the digits of an integer in words
using System;

class IntegerToWords
{
    static void Main()
    {
        Console.Write("Enter an integer: ");
        int number = int.Parse(Console.ReadLine());

        Console.WriteLine("Number in words: " + ConvertToWords(number));
    }

    static string ConvertToWords(int number)
    {
        if (number == 0)
            return "Zero";

        // Array of words for powers of 10
        string[] powersOfTen = {
            "", "Thousand", "Million", "Billion"
        };

        string words = "";

        int count = 0;
        while (number > 0)
        {
            if (number % 1000 != 0)
            {
                string str = ConvertThreeDigitsToWords(number % 1000);
                words = str + " " + powersOfTen[count] + " " + words;
            }
            number /= 1000;
            count++;
        }

        return words.Trim();
    }

    static string ConvertThreeDigitsToWords(int number)
    {
        // Array of words for single digits
        string[] singleDigits = {
            "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine"
        };

        // Array of words for teens
        string[] teens = {
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };

        // Array of words for tens
        string[] tens = {
            "Ten", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };
        string words = "";

        // Extracting hundreds place
        if (number >= 100)
        {
            words += singleDigits[number / 100 - 1] + " Hundred ";
            number %= 100;
        }

        // Handling tens and ones place
        if (number >= 20)
        {
            words += tens[number / 10 - 1] + " ";
            number %= 10;
        }
        else if (number >= 11)
        {
            words += teens[number - 11] + " ";
            number = 0;
        }

        // Handling ones place
        if (number > 0)
        {
            words += singleDigits[number - 1] + " ";
        }

        return words.Trim();
    }
}
