class Solution:
    def minPair(self, v: List[int]) -> int:
        min_sum = 10**9
        pos = -1
        for i in range(len(v) - 1):
            if v[i] + v[i + 1] < min_sum:
                min_sum = v[i] + v[i + 1]
                pos = i
        return pos
    def mergePair(self, v: List[int], pos: int) -> None:
        v[pos] += v[pos + 1]
        del v[pos + 1]

    def minimumPairRemoval(self, nums: List[int]) -> int:
        ops = 0
        while nums != sorted(nums): 
            self.mergePair(nums, self.minPair(nums))
            ops += 1
        return ops