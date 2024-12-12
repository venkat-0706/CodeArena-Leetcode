import math
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        i = 0
        while i < k:
            gifts = sorted(gifts)
            sqrt = math.floor(math.sqrt(gifts[-1]))
            gifts[-1] = sqrt
            i +=1
        return sum(gifts)