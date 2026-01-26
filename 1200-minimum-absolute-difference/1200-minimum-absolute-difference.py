class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n =  len(arr)
        min_diff = float('inf')
        for i in range(1,n):
            diff = arr[i]- arr[i-1]
            min_diff = min(diff,min_diff)
        ans = []
        for i in range(1,n):
            if arr[i] - arr[i-1] == min_diff:
                ans.append([arr[i-1],arr[i]])
        return ans



