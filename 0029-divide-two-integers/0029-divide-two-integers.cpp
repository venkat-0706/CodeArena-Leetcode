class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (abs(divisor) == 1) return dividend * divisor;

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        int count = 0;

        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        while (absDividend >= absDivisor) {
            long long base = absDivisor;
            int x = 1;
            while (base <= (absDividend >> 1)) {
                base <<= 1;
                x <<= 1;
            }
            count += x;
            absDividend -= base;
        }

        return isNegative ? -count : count;
    }
};