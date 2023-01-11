class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = defaultdict(list)
        
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
            
        def dfs(parent: int, checkParent: int) -> int:
            res = 0
            
            for child in adj[parent]:
                if child == checkParent:
                    continue
                res += dfs(child, parent)
                
            if res or hasApple[parent]:
                return res + 2
            
            return 0
        
        return max(dfs(0, -1) - 2, 0)