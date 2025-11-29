class Solution {
public:
    double myPow(double x, long long n) {

        // Base case
        if (n == 0) return 1.0;

        // If exponent is negative
        if (n < 0) return 1.0 / myPow(x, -n);

        // Recursive case
        double half = myPow(x, n / 2);

        // If n is even
        if (n % 2 == 0) 
            return half * half;

        // If n is odd
        return half * half * x;
    }
};