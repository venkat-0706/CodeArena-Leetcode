class Solution:
    def maxGap(self,arr):
        arr.sort()
        best = curr = 1
        for i in range(1, len(arr)):
            if arr[i] == arr[i-1]+1:
                curr += 1
            else:
                curr =  1
            best = max(best, curr)
        return best + 1
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        h = self.maxGap(hBars)
        v = self.maxGap(vBars)
        side = min(v,h)
        return side*side
        