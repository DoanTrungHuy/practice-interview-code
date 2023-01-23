class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parent = list(range(n))
        
        def find(u: int) -> int:
            if u != parent[u]:
                parent[u] = find(parent[u])
            return parent[u]
        
        self.cnt = n
        
        def union(u: int, v: int) -> None:
            u = find(u)
            v = find(v)
            if u == v:
                return
            parent[u] = v
            self.cnt -= 1
        
        for u in range(n):
            for v in range(n):
                if isConnected[u][v]:
                    union(u, v)
        
        return self.cnt
        