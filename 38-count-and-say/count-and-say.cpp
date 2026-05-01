class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string next = "";
            int len = res.length();
            
            for (int j = 0; j < len; j++) {
                int count = 1;
                while (j + 1 < len && res[j] == res[j + 1]) {
                    count++;
                    j++;
                }
                next += to_string(count) + res[j];
            }
            res = next;
        }
        
        return res;
    }
};