class Solution:
    def numOfWays(self, n: int) -> int:
        ans , res , mod = 6,6, 10**9+7
        for i in range(n-1):
            res,ans = res*3 + ans*2  , res*2+ans*2
        return (res+ans)%mod
        