class Solution:
    def findRepeatedDnaSequences(self, s: str)-> List[str]:
        L=10
        seen,res = set(),set()
        for i in range(len(s)-L+1):
            substr = s[i:i+L]
            if substr in seen:
                res.add(substr)
            else:
                seen.add(substr)
        return list(res)
        