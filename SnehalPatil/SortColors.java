class Solution {
    int redPtr = 0;
    int bluePtr = 0;

    public void sortColors(int[] nums) {
        bluePtr = nums.length - 1;
        
        while(int i < nums.length) {
            if (nums[i] == 0) {
                pushFront(nums, i);
                if (nums[i] == 2) {
                    pushBehind(nums, i);
                }
            }

            if (nums[i] == 2) {
                pushBehind(nums, i);
                if (nums[i] == 0) {
                    pushFront(nums, i);
                }
            }
            i++;
        }
    }
    public void pushFront(int[] nums, int i) {
        while (redPtr < nums.length && nums[redPtr] == 0) {
            redPtr++;
        }
        if (i > redPtr)
            swap(nums, i, redPtr);
    }

    public void pushBehind(int[] nums, int i) {
        while(bluePtr >=0 && nums[bluePtr] == 2) {
            bluePtr--;
        }
        if(i < bluePtr)
            swap(nums, i, bluePtr);
    }

    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
        
}