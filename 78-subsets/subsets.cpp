class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Every state in the recursion tree is a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // 1. Include the element
            current.push_back(nums[i]);
            
            // 2. Move to the next element
            backtrack(i + 1, nums, current, result);
            
            // 3. Backtrack (Exclude the element)
            current.pop_back();
        }
    }
};