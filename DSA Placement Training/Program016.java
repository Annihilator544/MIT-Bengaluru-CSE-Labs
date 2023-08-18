public class Program016 {
        public int search(int[] nums, int target) {
            // define pointers
            int left = 0, right = nums.length - 1;
            
            // Loop while to narrow down left and right pointer
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nums[mid] == target) return mid;
                
                // These line of code will do:
                // From middle, we will look from LEFT and RIGHT to know LEFT portion is SORTED or RIGHT portion is SORTED
                // Besides, we use target to narrow down left and right pointer
                if(nums[left] <= nums[mid]){
                    // from left to mid, all elements are sorted. It means LEFT portion of mid are SORTED
                    // find target belong to THIS LEFT portion or not
                    // [4,5,6,7,8,9,0,1,2]
                    //  l       m       r
                    //  l     r            (Ex: target = 5) - YES                
                    //            l     r. (Ex: target = 1) - NO   
                    if(nums[left] <= target && target < nums[mid]){ // Why we check target < nums[mid] (NOT target <= nums[mid]) HERE, BECAUSE we checked ABOVE (if(nums[mid] == target) return mid;)
                        // YES: target belong to LEFT portion that sorted
                        right = mid - 1;
                    } else {
                        // NO: target belong to RIGHT portion (BUT we not sort it is sorted or not)
                        left = mid + 1;
                    }                
                } else if (nums[mid] <= nums[right]) {
                    // from mid to right, all elements are sorted. It means RIGHT portion of mid are SORTED
                    // find target belong to THIS RIGHT portion or not
                    // [7,8,0,1,2,4,5,6,9]
                    //  l       m       r
                    //            l     r. (Ex: target = 5) - YES
                    //  l     r            (Ex: target = 1) - NO
                    if(nums[mid] < target && target <= nums[right]){ // Why we check &&  nums[mid] < target (NOT nums[mid] <= target) HERE, BECAUSE we checked ABOVE (if(nums[mid] == target) return mid;)
                        // YES: target belong to RIGHT portion that sorted
                        left = mid + 1;
                    } else {
                        // NO: target belong to LEFT portion (BUT we not sort it is sorted or not)
                        right = mid - 1;
                    }
                }
                
                // When we go here, we DID narrow down left and right pointer. 
                // The loop while will continue AND left and right pointer will be NARROW down again and again (In worst case, left = right = middle)
                // If target found on array, we will found it at MIDDLE and return. (at line - if(nums[mid] == target) return mid;)
                // If not, we will go out of loop and RETURN -1 at the end.
            }
            
            return -1;
        }
    public static void main(String[] args){
        int a[]={4,5,6,7,8,9,0,1,2};
        int target=5;
        long begin =System.currentTimeMillis();
        Program016 obj=new Program016();
        System.out.println(obj.search(a, target));
        long end = System.currentTimeMillis();
        System.out.println("Time taken to search: "+(end-begin)+"ms");
    }
}
