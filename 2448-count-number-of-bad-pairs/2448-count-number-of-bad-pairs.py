class Solution:
    def countBadPairs(self, A: List[int]) -> int:
        m, ans = defaultdict(int), 0
        for i in range(len(A)):
            ans += i - m[A[i] - i]
            m[A[i] - i] += 1
        return ans

        