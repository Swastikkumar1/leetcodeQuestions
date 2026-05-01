class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // While the current number is in range [1, n] 
            // and not at its correct position (nums[i]-1), swap it.
            // We use a while loop because the swapped number might also need moving.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Second pass: find the first index where the number is incorrect
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers 1 to n are present, the missing one is n + 1
        return n + 1;
    }
};