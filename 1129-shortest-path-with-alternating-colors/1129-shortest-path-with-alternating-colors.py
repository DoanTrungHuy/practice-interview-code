class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        
        for a, b in redEdges:
            adj[a].append((b, 1))
            
        for u, v in blueEdges:
            adj[u].append((v, 2))
            
        ans = [-1 for _ in range(n)]
        dq = deque([(0, 0, -1)])
        visited = set([(0, -1)])
        
        while dq:
            u, dist, color = dq.popleft()
            
            if ans[u] == -1:
                ans[u] = dist
            
            for pack in adj[u]:
                v, nextColor = pack
                if color != nextColor and (v, nextColor) not in visited:
                    visited.add((v, nextColor))
                    dq.append((v, dist + 1, nextColor))
                    
        return ans
                