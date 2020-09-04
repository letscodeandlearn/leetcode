class Solution {
    public int mySqrt(int x) {
        if ( x < 2) {
            return x;
        }
        
        int l = 1;
        int r = x;
        
        while (l < r) {
            int mid = l + (r - l)/2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                r = mid;
            } else if (mid * mid < x){
                l = mid + 1;
            }
        }
        
        return l - 1;
    }
}

// Doesnt work for larger number, need to work on it
