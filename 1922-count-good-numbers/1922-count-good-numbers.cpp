class Solution {
public:
    static const long long MOD = 1000000007;
    long long power(long long base, long long exp){
        if(exp == 0) return 1;
        if(exp % 2 == 0){
            long long half = power(base, exp/2);
            return (half * half) % MOD;
        }
        return (base * power(base, exp-1)) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;

        long long ans = (power(5, evenCount) * power(4, oddCount)) % MOD;
        return ans;
    }
};