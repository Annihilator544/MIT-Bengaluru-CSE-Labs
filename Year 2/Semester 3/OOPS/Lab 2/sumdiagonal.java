import java.util.*;
public class sumdiagonal{
	static void checkSymmetric(int mat[][], int row,int col)
	{
		int i, j, flag = 1;
		System.out.println("The matrix formed is:");
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				System.out.print(mat[i][j] + "\t");
			}

			System.out.println("");
		}

		int[][] transpose = new int[row][col];
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				transpose[j][i] = mat[i][j];
			}
		}
		if (row == col) {
			for (i = 0; i < row; i++) {
				for (j = 0; j < col; j++) {
					if (mat[i][j] != transpose[i][j]) {
						flag = 0;
						break;
					}}
				if (flag == 0) {
					System.out.println("\nThe matrix is not symmetric");
					break;
				}
			}
			if (flag == 1) {
				System.out.println("\nThe matrix is symmetric");
			}
		}
		else {
			System.out.println("\nThe matrix is not symmetric");
		}
	}
	static void sum_principal(int mat[][],int row,int col)
	{
                  int principal = 0;
       	 for (int k = 0; k < row; k++) {
           	 principal += mat[k][k];
			System.out.println(mat[k][k]);
       	 }
		System.out.println("Principal Diagonal:"+ principal);

	}
     
       static void sum_non_principal(int mat[][],int row,int col)
	{
                  int secondary = 0;
       	 for (int k = 0; k < row; k++) {
           	 secondary += mat[k][row - k - 1];
			System.out.println(mat[k][row - k - 1]);
       	 }
             System.out.println("Secondary Diagonal:" + secondary);

	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int i, j, row, col;
		System.out.print("Enter the number of rows:");
		row = sc.nextInt();
		System.out.print("Enter the number of columns:");
		col = sc.nextInt();
		int[][] mat = new int[row][col];
		System.out.println("Enter the matrix elements:");
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				mat[i][j] = sc.nextInt();
			}
		}
		checkSymmetric(mat, row, col);
 sum_principal(mat,row,col);
	sum_non_principal(mat,row,col);
    }}
	
