class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Decision: Start a new subarray at current element, 
            // or add current element to the existing subarray?
            currentMax = max(nums[i], currentMax + nums[i]);
            
            // Update the global maximum if the current subarray is better
            maxSoFar = max(maxSoFar, currentMax);
        }

        return maxSoFar;
    }
};