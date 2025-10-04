class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        b , s , b2 , s2 = -prices[0] , 0, -prices[0], 0
        for i in range(1,len(prices)):
            p = prices[i]
            b = max(b,-p)
            s = max(s,b+p)
            b2 = max(b2,s-p)
            s2 = max(s2,b2+p)
        return s2
        