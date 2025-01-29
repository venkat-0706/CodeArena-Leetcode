class Solution:
    # Performs DFS and returns True if there's a path between src and target.
    def _is_connected(self, src, target, visited, adj_list):
        visited[src] = True

        if src == target:
            return True

        is_found = False
        for adj in adj_list[src]:
            if not visited[adj]:
                is_found = is_found or self._is_connected(
                    adj, target, visited, adj_list
                )

        return is_found

    def findRedundantConnection(self, edges):
        N = len(edges)

        adj_list = [[] for _ in range(N)]

        for edge in edges:
            visited = [False] * N

            # If DFS returns True, we will return the edge.
            if self._is_connected(edge[0] - 1, edge[1] - 1, visited, adj_list):
                return edge

            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)

        return []