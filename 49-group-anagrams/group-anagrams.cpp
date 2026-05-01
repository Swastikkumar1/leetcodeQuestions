class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store {sorted_string : list_of_original_strings}
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sort the string to create the key
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};