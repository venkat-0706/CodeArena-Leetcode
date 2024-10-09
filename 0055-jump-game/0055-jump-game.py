class Solution:
    def canJump(self, nums: List[int]) -> bool:
        count  = 0
        for n in nums:
            if count < 0:
                return False
            elif count > 0:
                count = n
            count = count - 1
        return True




class Solution:
    def canJump(self, nums: List[int]) -> bool:
        gas = 0
        for n in nums:
            if gas < 0:
                return False
            elif n > gas:
                gas = n
            gas -= 1
            
        return True