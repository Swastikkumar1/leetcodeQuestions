#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> dp_max(m, vector<long long>(n));
        vector<vector<long long>> dp_min(m, vector<long long>(n));

        dp_max[0][0] = dp_min[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp_max[i][0] = dp_min[i][0] = dp_max[i - 1][0] * grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp_max[0][j] = dp_min[0][j] = dp_max[0][j - 1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    dp_max[i][j] = max(dp_max[i - 1][j], dp_max[i][j - 1]) * grid[i][j];
                    dp_min[i][j] = min(dp_min[i - 1][j], dp_min[i][j - 1]) * grid[i][j];
                } else {
                    dp_max[i][j] = min(dp_min[i - 1][j], dp_min[i][j - 1]) * grid[i][j];
                    dp_min[i][j] = max(dp_max[i - 1][j], dp_max[i][j - 1]) * grid[i][j];
                }
            }
        }

        long long res = dp_max[m - 1][n - 1];
        return res < 0 ? -1 : res % MOD;
    }
};