class Solution {
public:
    string result = "";
    int count = 0;

    void backtrack(int n, int k, string &current) {
        if (!result.empty()) return;

        if (current.length() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                current.push_back(c);
                backtrack(n, k, current);
                current.pop_back(); 
            }
        }
    }

    string getHappyString(int n, int k) {
        string current = "";
        backtrack(n, k, current);
        return result;
    }
};