class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        res = []
        max_num = max(candies)
        for num in candies:
            res.append(num + extraCandies >= max_num)
        return res
        