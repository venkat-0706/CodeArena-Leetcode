class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        res , prev = 1,1
        for i in range(1,n):
            if prices[i] == prices[i-1]-1:
                prev += 1
            else:
                prev = 1
            res += prev
        return res
        