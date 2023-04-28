class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        m, n = len(strs), len(strs[0])
        self.parent = [u for u in range(m)]
        self.group = m
    
        def find(u):
            if u != self.parent[u]:
                self.parent[u] = find(self.parent[u])
            return self.parent[u]
        
        def join(u, v):
            pu = find(u)
            pv = find(v)
            if pu != pv:
                self.parent[pu] = pv
                self.group -= 1
                
        def isSimilar(a, b):
            cnt = 0
            
            for i in range(n):
                if a[i] != b[i]:
                    cnt += 1
                if cnt > 2:
                    return False
                
            return cnt == 0 or cnt == 2
                
        
        for i in range(m):
            for j in range(i + 1, m):
                a = strs[i]
                b = strs[j]
                if isSimilar(a, b):
                    join(i, j)
                    
        return self.group