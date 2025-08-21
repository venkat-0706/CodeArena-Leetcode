class Solution:
    def findComplement(self, num: int) -> int:
        result = num.bit_length()
        mask = (1<<result) -1
        return num ^ mask
        