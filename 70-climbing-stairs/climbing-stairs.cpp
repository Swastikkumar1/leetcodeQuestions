class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 2) return n;

        int first = 1;  // Ways to reach 1st step
        int second = 2; // Ways to reach 2nd step
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = first + second;
            // Move our pointers forward
            first = second;
            second = current;
        }

        return second;
    }
};