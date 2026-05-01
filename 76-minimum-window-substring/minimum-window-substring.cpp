class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Map to store the frequency of characters in t
        unordered_map<char, int> targetFreq;
        for (char c : t) targetFreq[c]++;

        // Map to store frequency of characters in current window
        unordered_map<char, int> windowFreq;

        int left = 0, right = 0;
        int required = targetFreq.size(); // Number of unique chars in t
        int formed = 0; // Number of unique chars in current window meeting targetFreq
        
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowFreq[c]++;

            // If the current character's frequency matches the target frequency
            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (left <= right && formed == required) {
                c = s[left];

                // Update the result if this window is smaller than the previous best
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                windowFreq[c]--;
                // If removing the char makes the window invalid
                if (targetFreq.count(c) && windowFreq[c] < targetFreq[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};