class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        forbidden = set(forbidden)
        ma = max(x, max(forbidden)) + a + b
        visited = set()
        dq = deque([(0, 0, True)])
        
        while dq:
            j, step, forward = dq.popleft()
            
            if j == x:
                return step
            
            jr = j + a
            if jr <= ma and jr not in forbidden and (jr, True) not in visited:
                dq.append((jr, step + 1, True))
                visited.add((jr, True))
            
            jl = j - b
            if forward and 0 < jl and jl not in forbidden and (jl, False) not in visited:
                dq.append((jl, step + 1, False))
                visited.add((jl, False))
                
        return -1