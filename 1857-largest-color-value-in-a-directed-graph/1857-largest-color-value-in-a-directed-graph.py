class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        
        for u, v in edges:
            adj[u].append(v)
            
        visited, path = set(), set()
        n = len(colors)
        count = [26 * [0] for _ in range(n)]
        
        def dfs(u):
            if u in path:
                return float('inf')
            
            if u in visited:
                return 0
            
            path.add(u)
            visited.add(u)
            indexColor = ord(colors[u]) - ord('a')
            count[u][indexColor] = 1
            
            for v in adj[u]:
                if dfs(v) == float('inf'):
                    return float('inf')
                
                for i in range(26):
                    count[u][i] = max(
                        count[u][i],
                        int(indexColor == i) + count[v][i]
                    )
            
            path.remove(u)
            
            return max(count[u])
            
        res = 0
        
        for u in range(n):
            res = max(res, dfs(u))
            
        return -1 if res == float('inf') else res