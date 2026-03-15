class Fancy {
    long long totalMult = 1;
    long long totalAdd = 0;
    vector<long long> nums;
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val) {
        long long normalized = (val - totalAdd + MOD) % MOD;
        normalized = (normalized * modInverse(totalMult)) % MOD;
        nums.push_back(normalized);
    }

    void addAll(int inc) {
        totalAdd = (totalAdd + inc) % MOD;
    }

    void multAll(int m) {
        totalMult = (totalMult * m) % MOD;
        totalAdd = (totalAdd * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * totalMult + totalAdd) % MOD;
    }
};