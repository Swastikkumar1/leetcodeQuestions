class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // Signs can only appear at the very start 
                // OR immediately after an 'e' or 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == 'e' || c == 'E') {
                // 'e' can only appear once AND there must be a digit before it
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false; // Reset to ensure a digit follows the 'e'
            } 
            else if (c == '.') {
                // Dot can only appear once AND cannot appear after 'e'
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            } 
            else {
                // Any other character (like 'a') is invalid
                return false;
            }
        }

        return seenDigit;
    }
};