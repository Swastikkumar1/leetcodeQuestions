class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0, lastWildcard = -1, sNextIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Pattern has '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                lastWildcard = pIdx;
                sNextIdx = sIdx;
                pIdx++; // Try matching empty sequence first
            } 
            // Case 3: Current characters don't match, check if we can backtrack to last '*'
            else if (lastWildcard != -1) {
                pIdx = lastWildcard + 1;
                sNextIdx++;
                sIdx = sNextIdx;
            } 
            // Case 4: No match and no wildcard to backtrack to
            else {
                return false;
            }
        }

        // Check for remaining '*' in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};