class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        n = len(arr)
        res = []
        for i in range(n-1,-1,-1):
            res.append(arr[i])
        return ' '.join(res)
        