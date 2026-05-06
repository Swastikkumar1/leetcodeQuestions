#include <vector>
#include <string>

class Solution {
public:
    void backtrack(string& s, int start, vector<string>& segments, vector<string>& result) {
        // If we have 4 segments and have used the whole string, it's valid
        if (segments.size() == 4) {
            if (start == s.length()) {
                result.push_back(segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3]);
            }
            return;
        }

        // Try lengths 1, 2, and 3 for the current segment
        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;

            string part = s.substr(start, len);
            int val = stoi(part);

            // Validation checks:
            // 1. No leading zeros (part[0] == '0' but length > 1)
            // 2. Value must be <= 255
            if ((part[0] == '0' && len > 1) || val > 255) {
                continue;
            }

            segments.push_back(part);
            backtrack(s, start + len, segments, result);
            segments.pop_back(); // Backtrack
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> segments;
        
        // Pruning: An IP address is at most 12 digits (3*4) and at least 4
        if (s.length() < 4 || s.length() > 12) return result;
        
        backtrack(s, 0, segments, result);
        return result;
    }
};