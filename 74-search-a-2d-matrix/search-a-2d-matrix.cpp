class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Treat the m x n matrix as a 1D array of size m * n
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Map the 1D index back to 2D coordinates
            // Row = index / number of columns
            // Col = index % number of columns
            int val = matrix[mid / n][mid % n];

            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};