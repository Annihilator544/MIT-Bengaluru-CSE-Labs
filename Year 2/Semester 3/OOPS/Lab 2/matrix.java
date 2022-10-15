import java.util.*;
public class matrix
{
public static void main(String args[])
{
int i,j,k,row1,row2,col1,col2;
int m1[][]= new int[10][10];
int m2[][]= new int[10][10];
int p[][]= new int[10][10];
int s[][]= new int[10][10];
Scanner sc= new Scanner(System.in);
System.out.println("Enter row and column of first matrix");
row1=sc.nextInt();
col1=sc.nextInt();
System.out.println("Enter elements of first matrix");
for(i=0;i<row1;i++)
{
for(j=0;j<col1;j++)
{
m1[i][j]=sc.nextInt();
}}
System.out.println("Enter row and column of second matrix");
row2=sc.nextInt();
col2=sc.nextInt();
System.out.println("Enter elements of first matrix");
for(i=0;i<row2;i++)
{
for(j=0;j<col2;j++)
{
m2[i][j]=sc.nextInt();
}}
if(col1==row2)
{
        for(i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                for (k = 0; k < col1; k++) {
                    p[i][j] += m1[i][k] * m2[k][j];
                }
            }}}
System.out.println("Multiplication of two matrices is: ");
       for(i=0;i<row1;i++)
       {
          for(j=0;j<col1;j++)
                {
                System.out.print(p[i][j]+ "\t");
               }
            System.out.println();
}
{
if(row1==row2 && col1 == col2)
{
for(i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                s[i][j] = m1[i][j] + m2[i][j];
            }
        }
System.out.println("Sum of two matrices is: ");
       for(i=0;i<row1;i++)
       {
          for(j=0;j<col1;j++)
                {
                System.out.print(s[i][j]+ "\t");
               }
            System.out.println();
}
}
else
System.out.println("Not possible");
}

}}