class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        adj = defaultdict(list)
        visited = defaultdict(bool)
        color = defaultdict(int)
        
        BLUE, RED = 1, 2 
        
        for u, v in dislikes:
            adj[u].append(v)
            adj[v].append(u)
            
        dq = deque()
        
        for i in range(1, n + 1):
            if visited[i]:
               continue
            
            dq.append(i)
            color[i] = BLUE
            
            while dq:
                u = dq.popleft()
                
                if visited[u]:
                    continue
                
                visited[u] = True
                
                for v in adj[u]:
                    if color[v] == color[u]:
                        return False
                    if color[u] == RED:
                        color[v] = BLUE
                    else:
                        color[v] = RED
                    dq.append(v)
                    
        return True