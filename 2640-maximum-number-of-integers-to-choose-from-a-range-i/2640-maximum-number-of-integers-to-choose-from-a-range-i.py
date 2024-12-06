class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned_set = set(banned)
        curr_sum = 0
        count = 0
        for num in range(1,n+1):
            if num in banned_set or curr_sum + num > maxSum:
                continue
            curr_sum += num
            count+= 1
        return count
        

        