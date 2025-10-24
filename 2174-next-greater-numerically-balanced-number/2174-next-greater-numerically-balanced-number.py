class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        return next(v for v in count(n+1) if all(starmap(eq,Counter(map(int,str(v))).items())))