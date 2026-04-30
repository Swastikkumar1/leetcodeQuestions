// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.length()) {
            char r = s[right];
            count[r]++;

            while (count[r] > 1) {
                char l = s[left];
                count[l]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};