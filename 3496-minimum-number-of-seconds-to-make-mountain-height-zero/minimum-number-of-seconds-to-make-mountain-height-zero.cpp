class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long minW = *min_element(workerTimes.begin(), workerTimes.end());
        long long high = minW * (long long)mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool isPossible(long long totalTime, int targetHeight, vector<int>& workerTimes) {
        long long totalReduced = 0;
        for (int w : workerTimes) {

            long long val = (2 * totalTime) / w;
            long long x = (sqrt(1 + 4 * val) - 1) / 2;
            totalReduced += x;
            if (totalReduced >= targetHeight) return true;
        }
        return totalReduced >= targetHeight;
    
    }
};