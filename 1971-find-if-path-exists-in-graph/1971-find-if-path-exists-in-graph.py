class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        parent = [v for v in range(n)]
        
        def findUnion(u):
            if u != parent[u]:
                parent[u] = findUnion(parent[u])
            return parent[u]
        
        def group(u, v):
            u = findUnion(u)
            v = findUnion(v)
            if u != v:
                parent[v] = u
                return False
            return True
        
        for u, v in edges:
            group(u, v)
            
        return group(source, destination)