class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalLen = wordCount * wordLen;

        unordered_map<string, int> wordFreq;
        for (const string& w : words) {
            wordFreq[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> currentWindow;
            int count = 0;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    currentWindow[word]++;
                    count++;

                    while (currentWindow[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentWindow[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentWindow.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};