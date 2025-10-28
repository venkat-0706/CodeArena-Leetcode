class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        def simulate(start,direction):
            copy = nums[:]
            curr = start
            while 0 <= curr < n:
                if copy[curr] == 0:
                    curr += direction
                else:
                    copy[curr] -= 1
                    direction *= -1
                    curr += direction
            return all(x==0 for x in copy)
        for i in range(n):
            if nums[i] == 0:
                if simulate(i,-1):
                    count+=1
                if simulate(i,1):
                    count+=1
        return count
                
        