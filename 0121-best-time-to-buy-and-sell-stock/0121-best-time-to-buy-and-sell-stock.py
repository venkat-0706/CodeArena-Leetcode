class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_price = prices[0]
        profit = 0
        for num in prices[1:]:
            if buy_price > num :
                buy_price = num
            profit = max(profit, num-buy_price)
        return profit



        