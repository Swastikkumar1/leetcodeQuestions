class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int max_el = 0;
        for (int num : nums) {
            max_el = max(max_el, num);
        }
        int max_possible_xor = 1;
        while (max_possible_xor <= max_el) {
            max_possible_xor <<= 1;
        }
        max_possible_xor <<= 1; 

        vector<bool> seen_pairs(max_possible_xor, false);
        vector<bool> seen_triplets(max_possible_xor, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                seen_pairs[nums[i] ^ nums[j]] = true;
            }
        }
        for (int pair_xor = 0; pair_xor < max_possible_xor; ++pair_xor) {
            if (seen_pairs[pair_xor]) {
                for (int num : nums) {
                    seen_triplets[pair_xor ^ num] = true;
                }
            }
        }

        int unique_count = 0;
        for (int i = 0; i < max_possible_xor; ++i) {
            if (seen_triplets[i]) {
                unique_count++;
            }
        }

        return unique_count;
    }
};