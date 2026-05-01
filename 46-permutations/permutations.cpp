class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: If we've reached the end of the array, a permutation is complete
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Swap the current element with the element at the start index
            swap(nums[start], nums[i]);
            
            // Recursively generate permutations for the remaining elements
            backtrack(nums, start + 1, result);
            
            // Backtrack: Swap back to restore the original array for the next iteration
            swap(nums[start], nums[i]);
        }
    }
};