class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        if n==0:
            return -1
        res = -1
        for i in range(n-1,-1,-1):
            curr = arr[i]
            arr[i] = res
            if curr> res:
                res = curr
        return arr
        