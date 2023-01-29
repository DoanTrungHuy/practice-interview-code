class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0 for _ in range(n)]
        
        def dfs(u: int, color: int) -> bool:
            colors[u] = color
            for v in graph[u]:
                if colors[v] == -color:
                    continue
                if colors[v] == color or not dfs(v, -color):
                    return False
            return True
        
        for i in range(n):
            if colors[i] == 0 and not dfs(i, 1):
                return False
        
        return True