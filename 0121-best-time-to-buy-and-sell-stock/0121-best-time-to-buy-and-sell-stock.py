class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        prof = 0
        for p in prices[1:]:
            if buy > p:
                buy = p
            prof = max(prof , p-buy)
        return prof
        