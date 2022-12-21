class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        adj = [[] for _ in range(n + 1)]
        
        for u, v in dislikes:
            adj[u].append(v)
            adj[v].append(u)
            
        color = [0 for _ in range(n + 1)]
        
        def dfs(u, tincture):
            if color[u] != 0:
                return color[u] == tincture
            color[u] = tincture
            for v in adj[u]:
                if not dfs(v, -tincture):
                    return False
            return True
            
        for u in range(1, n + 1):
            if not color[u] and not dfs(u, 1):
                return False
        
        return True