class Solution:
    def maxSideLength(self, g: List[List[int]], t: int) -> int:
        m,n,p = len(g),len(g[0]),[*zip(*map(accumulate,zip(*map(accumulate,g))))]
        check = lambda q: all(p[i][j]-(i>=q and p[i-q][j])-(j>=q and p[i][j-q])+
            (i>=q<=j and p[i-q][j-q])>t for i,j in product(range(q-1,m),range(q-1,n)))
        return bisect_left(range(1,min(m,n)+1),1,key=check)