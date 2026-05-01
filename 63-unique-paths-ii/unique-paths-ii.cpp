class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start or end is an obstacle, no paths are possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        // Use a 1D DP array to save space
        vector<long long> dp(n, 0);
        
        // Base case: Starting point
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    // Obstacle found: no ways to reach this cell
                    dp[j] = 0;
                } else if (j > 0) {
                    // Standard DP relation: ways from top (dp[j]) + ways from left (dp[j-1])
                    // Note: dp[j] currently holds the value from the row above
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[n - 1];
    }
};