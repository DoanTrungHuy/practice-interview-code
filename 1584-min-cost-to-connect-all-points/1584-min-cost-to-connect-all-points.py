class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        adj = list()
        n = len(points)
        
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj.append((dist, i, j))
                
        adj.sort()
        parent = list(range(n))
        
        def find(u: int) -> int:
            if u != parent[u]:
                parent[u] = find(parent[u])
            return parent[u]
        
        def union(u: int, v: int) -> bool:
            u = find(u)
            v = find(v)
            if u != v:
                parent[u] = v
                return True
            return False
        
        m = len(adj)
        ans = 0
        
        for i in range(m):
            dist, u, v = adj[i]
            if union(u, v):
                ans += dist
                
        return ans