class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        if abs(divisor) == 1:
            return dividend * divisor

        is_negative = (dividend < 0) ^ (divisor < 0)
        count = 0

        dividend, divisor = abs(dividend), abs(divisor)

        while dividend >= divisor:
            x = 1
            base = divisor
            while base <= (dividend >> 1):
                base <<= 1
                x <<= 1
            count += x
            dividend -= base

        return -count if is_negative else count