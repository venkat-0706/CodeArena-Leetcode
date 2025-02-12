class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        dict_map = {}
        
        res = -1
        for num in nums:
            temp = num
            new_num = 0
            while temp:
                new_num += temp % 10
                temp = temp // 10
            if new_num in dict_map:
                new_res = num + dict_map[new_num]
                res = max(res, new_res)
                dict_map[new_num] = max(num, dict_map[new_num])
            else:
                dict_map[new_num] = num
        return res