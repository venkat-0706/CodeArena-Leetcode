class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = []
        total = 1<<n
        for i in range(total):
            res.append(i^(i>>1))
        return res
        