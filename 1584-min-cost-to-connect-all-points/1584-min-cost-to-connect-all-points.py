class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        adj = defaultdict(list)
        n = len(points)
        
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append((dist, j))
                adj[j].append((dist, i))
                
        heap = [(0, 0)]
            
        res = 0
        visited = set()
        
        while len(visited) < n:
            dist, u = heappop(heap)
            if u in visited:
                continue
            visited.add(u)
            res += dist
            for dv, v in adj[u]:
                if v not in visited:
                    heappush(heap, (dv, v))
                
        return res