import heapq
class Solution:
    def trapRainWater(self, heightMap):
        if not heightMap or not heightMap[0]:
            return 0

        numOfRows, numOfCols = len(heightMap), len(heightMap[0])
        visited = [[False] * numOfCols for _ in range(numOfRows)]
        heap = []

        for i in range(numOfRows):
            heapq.heappush(heap, (heightMap[i][0], i, 0))
            heapq.heappush(heap, (heightMap[i][numOfCols - 1], i, numOfCols - 1))
            visited[i][0] = visited[i][numOfCols - 1] = True

        for j in range(numOfCols):
            heapq.heappush(heap, (heightMap[0][j], 0, j))
            heapq.heappush(heap, (heightMap[numOfRows - 1][j], numOfRows - 1, j))
            visited[0][j] = visited[numOfRows - 1][j] = True

        totalWaterVolume = 0
        directions = [(0,1), (0,-1), (1,0), (-1,0)]

        while heap:
            height, row, col = heapq.heappop(heap)
            for dr, dc in directions:
                nr, nc = row + dr, col + dc
                if 0 <= nr < numOfRows and 0 <= nc < numOfCols and not visited[nr][nc]:
                    visited[nr][nc] = True
                    neighborHeight = heightMap[nr][nc]
                    totalWaterVolume += max(0, height - neighborHeight)
                    heapq.heappush(heap, (max(neighborHeight, height), nr, nc))

        return totalWaterVolume
