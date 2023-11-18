public class Program034 {
    public int findDuplicate(int[] nums) {
        //leetcode 287
        //https://leetcode.com/problems/find-the-duplicate-number/
        //floyd's tortoise and hare algorithm
        int slow=nums[0];
        int fast=nums[0];
        do{//find the intersection point of the two runners
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);//when slow and fast meet, they are at the start of the cycle
        fast=nums[0];
        while(slow!=fast)//when slow and fast meet, they are at the start of the cycle
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;   
    }
}
