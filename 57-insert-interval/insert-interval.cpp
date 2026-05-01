class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // Phase 1: Add all intervals that end before the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge overlapping intervals with the new interval
        // Overlap exists as long as current interval starts before or at the newInterval's end
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged newInterval
        result.push_back(newInterval);

        // Phase 3: Add all remaining intervals that start after the new interval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};