class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        k = k % total;
        if (k == 0) return grid;
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int current_1d = i * n + j;
                int new_1d = (current_1d + k) % total;
                int new_row = new_1d / n;
                int new_col = new_1d % n;
                
                result[new_row][new_col] = grid[i][j];
            }
        }
        
        return result;
    
    }
};