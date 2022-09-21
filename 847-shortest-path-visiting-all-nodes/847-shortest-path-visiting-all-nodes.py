class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        adj = defaultdict(list)
        n = len(graph)
        
        for u in range(n):
            for v in graph[u]:
                adj[u].append(v)
        
        dp = [[False] * (1 << n) for i in range(n)]
        
        dq = deque([])
        
        for i in range(n):
            dp[i][1 << i] = True
            dq.append((i, 1 << i, 0))
        
        allNode = (1 << n) - 1
        
        while dq:
            u, visited, step = dq.popleft()
            
            if visited == allNode:
                return step
            
            for v in adj[u]:
                mask_v = visited | (1 << v)
                if not dp[v][mask_v]:
                    dp[v][mask_v] = True
                    dq.append((v, mask_v, step + 1))
                
        return -1