class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS if the first character matches
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Base Case: All characters found
        if (index == word.length()) {
            return true;
        }

        // Boundary and character match check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // 1. Choose: Mark the cell as visited using a placeholder
        char temp = board[r][c];
        board[r][c] = '#'; 

        // 2. Explore: Try all 4 directions (Up, Down, Left, Right)
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // 3. Backtrack: Restore the cell for other potential paths
        board[r][c] = temp;

        return found;
    }
};