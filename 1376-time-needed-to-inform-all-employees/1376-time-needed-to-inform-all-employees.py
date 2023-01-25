class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = defaultdict(list)
        n = len(manager)
        
        for i in range(n):
            if manager[i] != -1:
                adj[manager[i]].append(i)
                
        def dfs(u: int) -> int:
            ans = 0
            
            for v in adj[u]:
                ans = max(ans, informTime[u] + dfs(v))
                
            return ans
        
        return dfs(headID)