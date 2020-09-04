class Solution {
    int right = 0;
    int left = 0;
    int mid = -1;
    int pivot = 0;
    public int search(int[] nums, int target) {
       	        // binary search as its a sorted array
	        int index = -1;
            right = nums.length - 1;
            pivot = getPivot(nums, left, right);
	        
	        
	        int arr1[] = new int[pivot];
	        int arr2[] = new int[nums.length - pivot];
	        for (int i = 0; i < pivot; i++) {
	        	arr1[i] = nums[i];
	        }
	        for (int i = 0, j = pivot; i < arr2.length || j < nums.length ; i++, j++) {
	        	arr2[i] = nums[j];
	        }
	        
	        index = getArr1(arr1, target);
	        if (index == -1) {
	        	index = getArr2(arr2, target);
	        }
	        return index;
	        
	    }
	    
	    public int getArr1(int[] arr, int target) {
	    	int left = 0;
	    	int right = arr.length - 1;
	    	while (left <= right) {
	            mid = left + (right - left)/2;
	            if (target == arr[mid]) {
	                return mid;
	            } else if (target > arr[mid]) {
	                left = mid + 1;
	            } else {
	                right = mid - 1;
	            }
	        }
	    	return -1;
	    }
	    
	    public int getArr2(int[] arr, int target) {
	    	int left = 0;
	    	int right = arr.length - 1;
	    	while (left <= right) {
	            mid = left + (right - left)/2;
	            if (target == arr[mid]) {
	                return mid  + pivot;
	            } else if (target > arr[mid]) {
	                left = mid + 1;
	            } else {
	                right = mid - 1;
	            }
	        }
	    	return -1;
	    }
    public int getPivot(int[] nums, int l, int r){
        
	        while (l <= r) {
                if (nums[l] <= nums[r]) {
                    return l;
                }
	            mid = l + (r - l)/2;
	            if ((nums[mid] > nums[r])) {
	                l = mid + 1;
	            } else {
	            	r = mid;
	            }
	        }
        return l;
    }
}
