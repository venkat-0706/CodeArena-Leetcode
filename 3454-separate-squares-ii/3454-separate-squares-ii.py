
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        edges = defaultdict(list); target = 0
        for left, down, a in squares:
            edges[down].append((1, left, left+a))
            edges[down+a].append((0, left, left+a))
            
        cur_edges = []; got = 0; cache = []
        def update_cur_edges(y):
            for add, a, b in edges[y]:
                if add:
                    insort_left(cur_edges, (a, b))
                else:
                    cur_edges.remove((a, b))

            width = 0; left = 0
            for a, b in cur_edges:
                if a >= left:
                    width += (b - a)
                    left = b
                elif b > left:
                    width += (b - left)
                    left = b
                #else skip
            return width                        

        for y,nexty in pairwise(sorted(edges)):
            width = update_cur_edges(y)
            got += (nexty - y) * width
            cache.append((nexty, width, got))
        
        target = got/2
        for entry in cache:
            if entry[2] >= target:
                return entry[0] - (entry[2] - target) / entry[1]