class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;           // Boundary for 0s
        int mid = 0;           // Current element scanner
        int high = nums.size() - 1; // Boundary for 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If we find a 0, swap it to the 'low' section
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If we find a 1, it's already in the middle section
                mid++;
            } 
            else { // nums[mid] == 2
                // If we find a 2, swap it to the 'high' section
                // Do NOT increment mid yet, because the swapped element 
                // from high hasn't been checked.
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};