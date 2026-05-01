class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters until the next space or start of string
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};