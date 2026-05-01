class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the edge case where n = INT_MIN
        // -INT_MIN exceeds the range of a standard 32-bit signed integer.
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        while (N > 0) {
            // If N is odd, multiply the result by current_product
            if (N % 2 == 1) {
                result *= current_product;
            }
            // Square the base and halve the exponent
            current_product *= current_product;
            N /= 2;
        }

        return result;
    }
};