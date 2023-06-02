class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        adj = defaultdict(list)
        
        for i in range(n):
            xi, yi, ri = bombs[i]
            for j in range(n):
                if i == j:
                    continue
                xj, yj, rj = bombs[j]
                if ri*ri >= (xi - xj)**2 + (yi - yj)**2:
                    adj[i].append(j)
                    
        def dfs(i):
            visited.add(i)
            for j in adj[i]:
                if j not in visited:
                    dfs(j)
            return len(visited)
            
        ans = 0
            
        for i in range(n):
            visited = set()
            ans = max(ans, dfs(i))
        
        return ans