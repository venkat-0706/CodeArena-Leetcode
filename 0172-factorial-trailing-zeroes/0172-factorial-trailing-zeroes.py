class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        div = 5
        while n>= div:
            count += n // div
            div *= 5
        return count
        