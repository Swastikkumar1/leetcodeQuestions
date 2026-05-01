class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        map<int, int> counts;
        
        // Count the frequency of each number
        for (int num : nums) {
            counts[num]++;
        }
        
        backtrack(nums.size(), counts, current, result);
        return result;
    }

private:
    void backtrack(int n, map<int, int>& counts, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If the current permutation is the full length
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        // Iterate through unique numbers in the frequency map
        for (auto& [num, count] : counts) {
            if (count > 0) {
                // Choice: use this number
                current.push_back(num);
                counts[num]--;

                // Recursion
                backtrack(n, counts, current, result);

                // Backtrack: restore the state
                counts[num]++;
                current.pop_back();
            }
        }
    }
};