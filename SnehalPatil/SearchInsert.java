class Solution {
    public int searchInsert(int[] nums, int target) {
        // binary search as its a sorted array
        int right = nums.length - 1;
        int left = 0;
        int mid = -1;
        
        
        while (left <= right) {
            mid = left + (right - left)/2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
