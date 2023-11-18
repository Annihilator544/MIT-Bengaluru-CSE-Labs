public class Program049 {
    public void nextPermutation(int[] nums) {
        //leetcode 31
        int n = nums.length;
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            int j = n-1;
            while(j>=0 && nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1, n-1);

    }
    public void swap(int nums[], int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void reverse(int nums[], int i, int j)
    {
        while(i<j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    public static void main(String args[])
    {
        int nums[] = {1,2,3};
        new Program049().nextPermutation(nums);
        for(int i=0; i<nums.length; i++)
        {
            System.out.print(nums[i]+" ");
        }
    }
}
