class Solution:
    def isTrionic(self, a: List[int]) -> bool:
        return [q for q,_ in groupby(map(sub,a[1:],a),lambda q:(q>0)-(q<0))]==[1,-1,1]