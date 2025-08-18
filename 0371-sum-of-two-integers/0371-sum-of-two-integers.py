class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        max_int = 0x7FFFFFF
        while b:
            carry = (a&b) & mask
            a=(a^b) & mask
            b = (carry<<1) & mask
        return a if a<= max_int else ~(a ^ mask)
        