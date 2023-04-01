class Solution:
    def findShortestCycle(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        ans = inf
        
        for node in range(n):
            dist = [inf for _ in range(n)]
            parent = [-1 for _ in range(n)]
            dist[node] = 0
            
            dq = deque([node])
            
            while dq:
                u = dq.popleft()
                for v in adj[u]:
                    if dist[v] == inf:
                        dist[v] = 1 + dist[u]
                        parent[v] = u
                        dq.append(v)
                    elif parent[u] != v and parent[v] != u:
                        ans = min(ans, dist[u] + dist[v] + 1)
                        
        return -1 if ans == inf else ans