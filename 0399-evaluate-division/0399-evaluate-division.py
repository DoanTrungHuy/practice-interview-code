class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj = defaultdict(list)
        n = len(equations)
        containV = set()
        
        for i in range(n):
            u = equations[i][0]
            v = equations[i][1]
            adj[u].append((v, values[i]))
            adj[v].append((u, 1 / values[i]))
            containV.add(u)
            containV.add(v)
            
        m = len(queries)
        ans = [-1 for _ in range(m)]
        self.visited = set()
        self.check = False
        self.total = 0
        
        def dfs(start, end, s):
            if start not in containV or end not in containV:
                return
            if start == end:
                self.check = True
                self.total = s
                return
            self.visited.add(start)
            for v, c in adj[start]:
                if v not in self.visited:
                    dfs(v, end, s * c)
        
        for i in range(m):
            start = queries[i][0]
            end = queries[i][1]
            dfs(start, end, 1)
            if self.check:
                ans[i] = self.total
            self.check = False
            self.total = 0
            self.visited = set()
            
        return ans