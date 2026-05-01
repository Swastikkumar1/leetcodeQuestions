class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Start with the first interval
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval added to our merged list
            vector<int>& last = merged.back();

            // 2. Check if the current interval overlaps with the last merged one
            // An overlap exists if current start <= last merged end
            if (intervals[i][0] <= last[1]) {
                // Merge them by updating the end time to the maximum found
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // 3. No overlap, so just add the current interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};