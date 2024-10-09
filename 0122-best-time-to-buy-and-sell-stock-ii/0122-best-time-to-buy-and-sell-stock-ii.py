class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        profit = 0
        for i in range(1,n):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        return profit

        