#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                
                vector<int> elements;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        elements.push_back(grid[r][c]);
                    }
                }

                sort(elements.begin(), elements.end());

                auto it = unique(elements.begin(), elements.end());
                elements.erase(it, elements.end());

                if (elements.size() <= 1) {
                    ans[i][j] = 0; 
                } else {
                    int minDiff = INT_MAX;
                    for (int p = 0; p < elements.size() - 1; ++p) {
                        minDiff = min(minDiff, elements[p+1] - elements[p]);
                    }
                    ans[i][j] = minDiff;
                }
            }
        }
        return ans;
    }
};