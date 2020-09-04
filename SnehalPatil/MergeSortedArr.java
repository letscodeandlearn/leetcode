class Solution {
    public void merge(int[] nums1, int i, int[] nums2, int j) {
        
        int k = (i + j) - 1;
        int m = i -1;
        int n = j-1;
        
        while (k > -1) {
            if (m == -1) {
                nums1[k--] = nums2[n--];
            } else if (n == -1){
                nums1[k--] = nums1[m--];
            } else {
                if(nums1[m] > nums2[n]) {
                nums1[k--] = nums1[m--];
            } else {
                nums1[k--] = nums2[n--];
            }
            }
            
        }
    }
}
