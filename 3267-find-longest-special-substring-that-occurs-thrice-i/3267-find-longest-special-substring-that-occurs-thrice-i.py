from collections import Counter
class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        temp = Counter()
        for i in range(n):
            ch = s[i]
            for l in range(1,n-i+1):
                sub = s[i:i+l]
                if sub == ch * l:
                    temp[sub] += 1
        lon = -1
        for sub , count in temp.items():
            if count >= 3:
                lon = max(lon,len(sub))
        return lon
        