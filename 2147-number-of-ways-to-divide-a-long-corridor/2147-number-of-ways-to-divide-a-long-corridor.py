class Solution:
    def numberOfWays(self, corridor: str) -> int:
        seat , res, plant = 0,1,0
        for i in corridor:
            if i=='S':
                seat += 1
            else:
                if seat ==2:
                    plant += 1
            if seat == 3:
                res =  res*(plant+1)%(10**9+7)
                seat,plant = 1,0
        if seat !=2:
            return 0
        return res