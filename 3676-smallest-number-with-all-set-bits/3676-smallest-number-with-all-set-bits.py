class Solution:
    def smallestNumber(self, n: int) -> int:
        return 2**n.bit_length()-1
        