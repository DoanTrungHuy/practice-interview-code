class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        deg = [0 for _ in range(n)]
        adj = defaultdict(list)
        
        for u, v in enumerate(edges):
            if v != -1:
                deg[v] += 1
                adj[u].append(v)
        
        dq = deque()
        color = [0 for _ in range(n)]
        
        for u in range(n):
            if deg[u] == 0:
                dq.append(u)
                color[u] = 2
                
        while dq:
            u = dq.popleft()
            
            for v in adj[u]:
                if color[v] == 2:
                    continue
                deg[v] -= 1
                if deg[v] == 0:
                    color[v] = 2
                    dq.append(v)
                    
        def dfs(u):
            color[u] = 1
            cnt = 1
            for v in adj[u]:
                if color[v] == 0:
                    cnt += dfs(v)
                elif color[v] == 1:
                    break 
            color[u] = 2
            return cnt
        
        ans = -1
        
        for u in range(n):
            if color[u] != 0:
                continue
            ans = max(ans, dfs(u))
        
        return ans