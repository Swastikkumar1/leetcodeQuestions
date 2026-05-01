class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Base cases for 0 and 1

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // We use division (x / mid) instead of (mid * mid) 
            // to prevent integer overflow since x can be up to 2^31 - 1
            if (mid <= x / mid) {
                ans = mid;    // mid is a potential candidate
                left = mid + 1; // Look for a larger value
            } else {
                right = mid - 1; // mid is too large
            }
        }

        return ans;
    }
};