class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if (Math.abs(divisor) == 1) return dividend * divisor;

        boolean isNegative = (dividend < 0) ^ (divisor < 0);
        int count = 0;

        long absDividend = Math.abs((long)dividend);
        long absDivisor = Math.abs((long)divisor);

        while (absDividend >= absDivisor) {
            long base = absDivisor;
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
}