class Solution {
    public int bluePtr = 0;
    public int redPtr = 0;
    
    public void swap(int[] nums, int indexA, int indexB) {
        int temp = nums[indexA];
        nums[indexA] = nums[indexB];
        nums[indexB] = temp;
    }
    
    public void pushBehind(int[] nums, int index) {
        while (this.bluePtr >= 0 && nums[this.bluePtr] == 2) this.bluePtr--;
        
         if (index < this.bluePtr) {
             this.swap(nums, index, this.bluePtr);
         }
    }
    
    public void pushFront(int[] nums, int index) {
        while (this.redPtr < nums.length && nums[this.redPtr] == 0) this.redPtr++;
        
         if (index > this.redPtr) {
             this.swap(nums, index, this.redPtr);
         }
        
    }
    
    public void sortColors(int[] nums) {
        this.bluePtr = nums.length - 1;
        int i = 0;
        int oldBluePtr;
        int oldRedPtr;
        
        while(i < nums.length) {
            oldBluePtr = this.bluePtr;
            oldRedPtr = this.redPtr;
            
            if (nums[i] == 0) {
                this.pushFront(nums, i);
                if (nums[i] == 2) this.pushBehind(nums, i);
            }
            
            if (nums[i] == 2) {
                this.pushBehind(nums, i);
                if (nums[i] == 0) this.pushFront(nums, i);
            }
            
            i++;
        } 
        
    }
}