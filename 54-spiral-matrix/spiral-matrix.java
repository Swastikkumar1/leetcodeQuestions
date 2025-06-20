class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int row = matrix.length;
        int col = matrix[0].length;

        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;

        while (ans.size() < row * col) {
            for (int i = left; i <= right && ans.size() < row * col; i++) {
                ans.add(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom && ans.size() < row * col; i++) {
                ans.add(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left && ans.size() < row * col; i--) {
                ans.add(matrix[bottom][i]);
            }
            bottom--;

            for (int i = bottom; i >= top && ans.size() < row * col; i--) {
                ans.add(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
}
