class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        adj = defaultdict(list)
        
        for u, v in enumerate(parent):
            if v == -1:
                continue
            adj[u].append(v)
            adj[v].append(u)
            
        self.res = 0
        
        def dfs(node, parent):
            max1, max2 = 0, 0
            for child in adj[node]:
                if child != parent:
                    curr = dfs(child, node)
                    if s[node] == s[child]:
                        continue
                    if curr > max1:
                        max2 = max1
                        max1 = curr
                    elif curr > max2:
                        max2 = curr
            self.res = max(self.res, max1 + max2 + 1)
            return max1 + 1
        
        dfs(0, -1)
        
        return self.res