class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int furthest = 0;

        for (int i = 0; i < n - 1; i++) {
            // Update the furthest index we can reach from the current position
            furthest = max(furthest, i + nums[i]);

            // If we have reached the end of the current jump's range
            if (i == currentEnd) {
                jumps++;
                currentEnd = furthest;
                
                // If the new range already reaches the end, we can stop
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};