class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        position = [-1] * 3
        total = 0

        for i in range(n):
            position[ord(s[i]) - ord("a")] = i
            total += 1 + min(position)

        return total