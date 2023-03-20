class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        visited = [False] * (n + 1)
        
        adj = defaultdict(list)
        
        def dfs(u, end):
            if u == end:
                return True
            visited[u] = True
            for v in adj[u]:
                if visited[v] == False:
                    if dfs(v, end):
                        return True
            return False
        
        for u, v in edges:
            if dfs(u, v):
                return [u, v]
            visited = [False] * (n + 1)
            adj[u].append(v)
            adj[v].append(u)
        
        return [-1, -1]