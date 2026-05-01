class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: If the combination is of length k, add to results
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization: Only loop if there are enough numbers left to fill k slots
        // n - i + 1 is the count of available numbers. 
        // k - current.size() is how many more we need.
        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            // 1. Choose the number
            current.push_back(i);
            
            // 2. Explore further (start from i + 1)
            backtrack(i + 1, n, k, current, result);
            
            // 3. Backtrack (remove the number)
            current.pop_back();
        }
    }
};