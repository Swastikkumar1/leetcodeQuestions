#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        // The sequence will contain 2^n elements
        int size = 1 << n; 
        std::vector<int> result;
        result.reserve(size);
        
        for (int i = 0; i < size; ++i) {
            // Standard Gray Code formula: i XOR (i divided by 2)
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};