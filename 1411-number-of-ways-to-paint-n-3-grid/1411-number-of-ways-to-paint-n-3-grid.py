class Solution:
    def numOfWays(self, n: int) -> int:
        res,ans, mod = 6,6, 10**9+7
        for i in range(n-1):
            ans , res = ans*3+res*2 , res*2+ans*2

        return (res+ans)%mod
        