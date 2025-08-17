class Solution:
    def fun(self,n):
        count =0
        while(n):
            count += n& 1
            n>>=1
        return count

    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=lambda x: (self.fun(x), x))
        

        