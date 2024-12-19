class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        count = 0
        curr = 0
        for i, x in enumerate(arr):
            curr = max(curr, x)
            if curr == i:
                count += 1
        return count