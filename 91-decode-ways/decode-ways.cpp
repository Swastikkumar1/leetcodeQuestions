#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        // dp[i] stores the number of ways to decode s.substr(0, i)
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // Empty string has one way to be decoded (doing nothing)
        dp[1] = 1; // We already checked s[0] != '0'
        
        for (int i = 2; i <= n; ++i) {
            // Check single digit (s[i-1])
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            
            // Check two digits (s[i-2] and s[i-1])
            int twoDigits = std::stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};