import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> m1 = new HashMap<>();

        for (int i = 0; i < n; i++) {
            m1.put(nums[i], m1.getOrDefault(nums[i], 0) + 1);
        }

        n = n / 2;

        for (Map.Entry<Integer, Integer> e1 : m1.entrySet()) {
            if (e1.getValue() > n) {
                return e1.getKey();
            }
        }

        return -1; 
    }
}
