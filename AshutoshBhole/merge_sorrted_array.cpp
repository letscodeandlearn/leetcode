/*
    URL: https://leetcode.com/problems/merge-sorted-array/
    Status: Accepted
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if  (n==0){
            return;
        }
            
        if (m == 0){
            for(int i = 0; i < nums2.size(); i++){
                nums1[i]= nums2[i];
            }
            return;
        }
        
        int max=0, maxIndx=0, small=0, large=0;
        
        for(small=0, large =0; small<nums2.size(), large<nums1.size();) {
            
            if(nums1[large] < nums2[small]) {
                large++;
            } else if (nums1[large] >= nums2[small]) {
                nums1.insert(nums1.begin()+large, nums2[small]);
                nums2.erase(nums2.begin()+small);
                if (nums2.size()==0) {
                    break;
                }
            }
        }

        int diffIndex = n-nums2.size();
        
        int itr=0;
        while(nums2.size()!=0) {
            nums1[m+diffIndex + itr++]= nums2[0];
            nums2.erase(nums2.begin());
        }

        while(nums1.size()> (m+n))
            nums1.erase(nums1.begin()+nums1.size()-1);
    }
};