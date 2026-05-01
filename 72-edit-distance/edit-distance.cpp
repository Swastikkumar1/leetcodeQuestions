class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // dp[i][j] = min operations for word1[0...i-1] to word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Fill base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Deletions
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Insertions

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, carry over the previous cost
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Choose the minimum of Insert, Delete, or Replace
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], // Replace
                                        dp[i - 1][j],     // Delete
                                        dp[i][j - 1]});    // Insert
                }
            }
        }

        return dp[m][n];
    }
};