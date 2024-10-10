class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        quadruplets = []
        n = len(nums)

        for a in range(n - 3):
            # Skip duplicate elements for the first position
            if a > 0 and nums[a] == nums[a - 1]:
                continue
            for b in range(a + 1, n - 2):
                # Skip duplicate elements for the second position
                if b > a + 1 and nums[b] == nums[b - 1]:
                    continue
                
                left, right = b + 1, n - 1
                
                while left < right:
                    current_sum = nums[a] + nums[b] + nums[left] + nums[right]
                    
                    if current_sum == target:
                        quadruplets.append([nums[a], nums[b], nums[left], nums[right]])
                        
                        # Skip duplicates for the third and fourth positions
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        
                        left += 1
                        right -= 1
                    elif current_sum < target:
                        left += 1
                    else:
                        right -= 1
        
        return quadruplets