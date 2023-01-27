class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = [False for _ in range(n)]
        dq = deque([start])
        
        def isValid(u: int) -> bool:
            return 0 <= u < n
        
        while dq:
            u = dq.popleft()
            visited[u] = True
            
            if arr[u] == 0:
                return True
            
            jl, jr = u + arr[u], u - arr[u]
            
            if isValid(jl) and not visited[jl]:
                dq.append(jl)
            
            if isValid(jr) and not visited[jr]:
                dq.append(jr)
                
        return False