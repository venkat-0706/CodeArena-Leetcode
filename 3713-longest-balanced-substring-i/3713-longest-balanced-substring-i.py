class Solution:
    def longestBalanced(self, s: str) -> int:
        cnt, n=1, len(s)
        for l in range(n):
            freq=[0]*26
            uniq, maxF, cntMax=0, 0, 0
            for r in range(l, n):
                freq[ord(s[r])-97]+=1
                f=freq[ord(s[r])-97]
                uniq+=f==1
                if f>maxF:
                    maxF=f
                    cntMax=1
                elif f==maxF:
                    cntMax+=1
                if uniq==cntMax:
                    cnt=max(cnt, r-l+1)
        return cnt