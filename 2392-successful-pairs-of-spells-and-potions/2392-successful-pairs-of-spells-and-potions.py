class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        freq=Counter(potions)
        pMax=max(freq)
        F=[0]*(1+pMax)
        for p, f in freq.items():
            F[p]=f
        freq=list(accumulate(F))
        n, m=len(spells), len(potions)
        res=[0]*n
        for i, x in enumerate(spells):
            k=(success+x-1)//x
            if k<=pMax:
                res[i]=m-freq[k-1]
        return res

        