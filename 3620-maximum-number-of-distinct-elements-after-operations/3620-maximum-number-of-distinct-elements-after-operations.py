from typing import List

class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        last_picked = -10**18
        distinct_count = 0

        for num in nums:
            lower_bound = num - k
            upper_bound = num + k
            if last_picked < lower_bound:
                last_picked = lower_bound
            else:
                last_picked += 1
            if last_picked <= upper_bound:
                distinct_count += 1
            else:
                last_picked -= 1

        return distinct_count