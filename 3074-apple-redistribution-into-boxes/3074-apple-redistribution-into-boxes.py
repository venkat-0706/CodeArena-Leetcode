class Solution:
    def minimumBoxes(self, apple: List[int], cap: List[int]) -> int:
        sum_apples = sum(apple) 
        cap.sort(reverse=True)

        res = 0
        while sum_apples > 0:
            sum_apples -= cap[res]
            res += 1

        return res
