class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If the current digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // If the digit is 9, it becomes 0 (carry moves to the next left digit)
            digits[i] = 0;
        }
        
        // If we exit the loop, it means all digits were 9 (e.g., 999 -> 000)
        // We need to add a '1' at the beginning (000 -> 1000)
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};