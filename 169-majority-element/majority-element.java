import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int n = 0;

        for (int i : nums) {
            if (count == 0) {
                n = i;
            }

            if (i == n) {
                count++;
            } else {
                count--;
            }
        }

        return n; 
    }
}

