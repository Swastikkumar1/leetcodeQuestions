class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If size is 0, 1, or 2, it's already valid

        // 'k' represents the index where the next valid element should be placed
        int k = 2; 

        for (int i = 2; i < n; i++) {
            // Compare the current element with the element two positions back 
            // in the modified part of the array.
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};