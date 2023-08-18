import java.util.Scanner;

public class Program015 {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rw = matrix.length, cl = matrix[0].length;
        int left = 0, right = rw * cl-1;
        while(left <= right){
            int midPos =  left + (right - left)/2;
            int r = midPos / cl, c = midPos % cl;
            if(matrix[r][c] == target){
                return true;
            }else if(matrix[r][c] < target){
                left = midPos + 1;
            }else{
                right = midPos - 1;
            }
        }
        return false;
    }
    public static void main(String[] args){
        System.out.println("Enter the Number of Rows and Columns:");
        Scanner sc= new Scanner(System.in);
        int R=sc.nextInt();
        int C=sc.nextInt();
        System.out.println("Enter the Elements of array:");
		int a[][]=new int[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                a[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the Target Element:");
        int target=sc.nextInt();
        sc.close();
        long begin =System.currentTimeMillis();
        Program015 obj=new Program015();
        System.out.println(obj.searchMatrix(a, target));
        long end = System.currentTimeMillis();
        System.out.println("Time taken to search: "+(end-begin)+"ms");
    }
}
