class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        n = len(arr)
        temp = []
        for i in range(n-1,-1,-1):
            temp.append(arr[i])
        return ' '.join(temp)
        
        