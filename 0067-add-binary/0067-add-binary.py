class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = int(a,2)
        j = int(b,2)
        while j:
            sum  = i^j
            carry = (i&j) <<1
            i,j = sum,carry
        return bin(i)[2:]
        