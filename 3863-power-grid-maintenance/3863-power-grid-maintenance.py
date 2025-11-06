class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        G = [[] for _ in range(c + 1)]
        for u, v in connections:
            G[u].append(v)
            G[v].append(u)

        seen = [0] * (c + 1)
        def dfs(i, v):
            if seen[i]: return
            seen[i] = v
            for j in G[i]:
                dfs(j, v)
            return

        for i in range(1, c + 1):
            dfs(i, i)

        todo = defaultdict(list)
        for i in range(c, 0, -1):
            todo[seen[i]].append(i)
        res = []
        online = [1] * (c + 1)
        for o, x in queries:
            if o == 1:
                if online[x]:
                    res.append(x)
                    continue
                y = seen[x]
                while todo[y] and online[todo[y][-1]] == 0:
                    todo[y].pop()
                res.append(todo[y][-1] if todo[y] else -1)
            if o == 2:
                online[x] = 0
        return res
        