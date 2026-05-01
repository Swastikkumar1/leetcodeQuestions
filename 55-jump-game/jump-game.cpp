class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // If the current index is greater than our max reachable point,
            // it means we've hit a gap we cannot cross.
            if (i > reachable) {
                return false;
            }

            // Update the furthest index we can reach from the current spot
            reachable = max(reachable, i + nums[i]);

            // Optimization: if we can already reach the end, return true
            if (reachable >= n - 1) {
                return true;
            }
        }

        return true;
    }
};