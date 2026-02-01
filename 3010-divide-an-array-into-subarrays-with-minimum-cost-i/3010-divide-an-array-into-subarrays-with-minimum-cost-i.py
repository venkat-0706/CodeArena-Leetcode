class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        m1, m2 = float("inf"), float("inf")
        for n in nums[1:]:
            m2 = min(m2, n)
            if m2 < m1:
                m1, m2 = m2, m1
        return nums[0] + m1 + m2
                
        