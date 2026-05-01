class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Use a 1D vector to store the minimum path sums for the current row
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // Base case: Starting point
                    dp[j] = grid[i][j];
                } else if (i == 0) {
                    // First row: Can only come from the left
                    dp[j] = dp[j - 1] + grid[i][j];
                } else if (j == 0) {
                    // First column: Can only come from above
                    // dp[j] already contains the value from the cell above (previous row)
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    // General case: Min of (from above, from left) + current cell value
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }

        return dp[n - 1];
    }
};