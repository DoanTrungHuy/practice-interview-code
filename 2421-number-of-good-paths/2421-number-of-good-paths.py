class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        n = len(vals)
        self.parent = list(range(n))
        adj = defaultdict(list)
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        merge = defaultdict(list)
        
        for node, val in enumerate(vals):
            merge[val].append(node)
        
        def find(u: int) -> int:
            if u != self.parent[u]:
                self.parent[u] = find(self.parent[u])
            return self.parent[u]
        
        def union(u: int, v: int) -> None:
            self.parent[find(u)] = find(v)
            
        ans = 0
        
        keys = sorted(merge.keys())
        
        for val in keys:
            nodes = merge[val]
            for u in nodes:
                for v in adj[u]:
                    if val >= vals[v]:
                        union(u, v)
            
            cnt = defaultdict(int)
            
            for u in nodes:
                ans += cnt[find(u)]
                cnt[find(u)] += 1
                
        return ans + n