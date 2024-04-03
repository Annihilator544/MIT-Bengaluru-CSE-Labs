//1.	Write a C# program for addition and multiplication of two matrices
using System;

class MatrixOperations
{
    static void Main()
    {
        // Define two matrices
        int[,] matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        int[,] matrix2 = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        };
        
        // Display the original matrices
        Console.WriteLine("Matrix 1:");
        DisplayMatrix(matrix1);
        Console.WriteLine("\nMatrix 2:");
        DisplayMatrix(matrix2);

        // Addition of matrices
        int[,] additionResult = AddMatrices(matrix1, matrix2);
        Console.WriteLine("\nAddition Result:");
        DisplayMatrix(additionResult);

        // Multiplication of matrices
        int[,] multiplicationResult = MultiplyMatrices(matrix1, matrix2);
        Console.WriteLine("\nMultiplication Result:");
        DisplayMatrix(multiplicationResult);
    }

    // Function to display a matrix
    static void DisplayMatrix(int[,] matrix)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }

    // Function to add two matrices
    static int[,] AddMatrices(int[,] matrix1, int[,] matrix2)
    {
        int rows = matrix1.GetLength(0);
        int cols = matrix1.GetLength(1);

        int[,] result = new int[rows, cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i, j] = matrix1[i, j] + matrix2[i, j];
            }
        }

        return result;
    }

    // Function to multiply two matrices
    static int[,] MultiplyMatrices(int[,] matrix1, int[,] matrix2)
    {
        int rows1 = matrix1.GetLength(0);
        int cols1 = matrix1.GetLength(1);
        int cols2 = matrix2.GetLength(1);

        int[,] result = new int[rows1, cols2];

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                int sum = 0;
                for (int k = 0; k < cols1; k++)
                {
                    sum += matrix1[i, k] * matrix2[k, j];
                }
                result[i, j] = sum;
            }
        }

        return result;
    }
}
