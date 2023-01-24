class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        parent = list(range(n))
        self.notConnected = n
        
        def find(u: int) -> int:
            if u != parent[u]:
                parent[u] = find(parent[u])
            return parent[u]
        
        def union(u: int, v: int) -> None:
            u, v = find(u), find(v)
            if u == v:
                return
            parent[u] = v
            self.notConnected -= 1
            
        for u, v in connections:
            union(u, v)
            
        return self.notConnected - 1