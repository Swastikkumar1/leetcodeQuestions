#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                total += grid[i][j];
        
        vector<long long> row_sum(m, 0), col_sum(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
            }
        unordered_map<int,int> top_freq, bot_freq;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                bot_freq[grid[i][j]]++;
        
        long long top_sum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                top_freq[v]++;
                if (--bot_freq[v] == 0) bot_freq.erase(v);
            }
            top_sum += row_sum[i];
            long long bot_sum = total - top_sum;
            int top_rows = i + 1, bot_rows = m - i - 1;
            
            if (top_sum == bot_sum) return true;
            
            long long diff = abs(top_sum - bot_sum);
            
            if (top_sum > bot_sum) {
                if (top_rows >= 2 && n >= 2) {
                    if (diff <= INT_MAX && top_freq.count((int)diff)) return true;
                } else if (top_rows == 1) {
                    if (grid[0][0] == diff || grid[0][n-1] == diff) return true;
                } else {
                    if (grid[0][0] == diff || grid[i][0] == diff) return true;
                }
            } else {
                if (bot_rows >= 2 && n >= 2) {
                    if (diff <= INT_MAX && bot_freq.count((int)diff)) return true;
                } else if (bot_rows == 1) {
                    if (grid[i+1][0] == diff || grid[i+1][n-1] == diff) return true;
                } else {
                    if (grid[i+1][0] == diff || grid[m-1][0] == diff) return true;
                }
            }
        }
        
        unordered_map<int,int> left_freq, right_freq;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                right_freq[grid[i][j]]++;
        
        long long left_sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int v = grid[i][j];
                left_freq[v]++;
                if (--right_freq[v] == 0) right_freq.erase(v);
            }
            left_sum += col_sum[j];
            long long right_sum = total - left_sum;
            int left_cols = j + 1, right_cols = n - j - 1;
            
            if (left_sum == right_sum) return true;
            
            long long diff = abs(left_sum - right_sum);
            
            if (left_sum > right_sum) {
                if (m >= 2 && left_cols >= 2) {
                    if (diff <= INT_MAX && left_freq.count((int)diff)) return true;
                } else if (m == 1) {
                    if (grid[0][0] == diff || grid[0][j] == diff) return true;
                } else {
                    if (grid[0][0] == diff || grid[m-1][0] == diff) return true;
                }
            } else {
                if (m >= 2 && right_cols >= 2) {
                    if (diff <= INT_MAX && right_freq.count((int)diff)) return true;
                } else if (m == 1) {
                    if (grid[0][j+1] == diff || grid[0][n-1] == diff) return true;
                } else {
                    if (grid[0][j+1] == diff || grid[m-1][j+1] == diff) return true;
                }
            }
        }
        
        return false;
    }
};