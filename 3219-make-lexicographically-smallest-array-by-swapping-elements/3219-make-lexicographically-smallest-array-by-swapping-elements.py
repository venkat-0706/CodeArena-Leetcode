class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        sorted_enum = sorted((num, i) for i, num in enumerate(nums))
        
        new_positions = []
        curr_positions = []
        prev = float('-inf')
        
        for num, idx in sorted_enum:
            if num > prev + limit:
                new_positions.extend(sorted(curr_positions))
                curr_positions = [idx]
            else:
                curr_positions.append(idx)
            prev = num
        new_positions.extend(sorted(curr_positions))
        res = [0] * n
        for i, idx in enumerate(new_positions):
            res[idx] = sorted_enum[i][0]
        
        return res