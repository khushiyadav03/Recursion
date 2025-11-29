class Solution {
public:
    static const long long MOD = 1000000007;

    // Simple Recursive Fast Power
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // even index positions
        long long oddCount  = n / 2;        // odd index positions

        long long ans = (power(5, evenCount) * power(4, oddCount)) % MOD;
        return (int)ans;
    }
};
