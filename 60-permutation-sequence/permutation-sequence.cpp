class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n);
        
        // 1. Precompute factorials and create a list of numbers {1, 2, ..., n}
        int fact = 1;
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
            factorial[i] = fact;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        // 2. Adjust k to be 0-indexed for easier math
        k--;

        string result = "";
        for (int i = n - 1; i >= 0; i--) {
            // Find the index of the number we need
            int index = k / factorial[i];
            
            // Append the number at that index to our result
            result += to_string(numbers[index]);
            
            // Remove that number so it isn't used again
            numbers.erase(numbers.begin() + index);
            
            // Update k for the next iteration
            k %= factorial[i];
        }

        return result;
    }
};