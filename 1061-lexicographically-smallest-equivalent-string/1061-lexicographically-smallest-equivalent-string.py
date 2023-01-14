class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        adj = defaultdict(list)
        
        for u, v in zip(s1, s2):
            adj[u].append(v)
            adj[v].append(u)
            
        def dfs(u: int, seen: set) -> int:
            seen.add(u)
            res = u
            for v in adj[u]:
                if v not in seen:
                    res = min(res, dfs(v, seen))
            return res
        
        return ''.join([dfs(char, set()) for char in baseStr])