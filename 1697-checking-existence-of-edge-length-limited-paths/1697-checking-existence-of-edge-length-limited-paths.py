class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        self.parent = [u for u in range(n)]
        
        def find(u):
            if u != self.parent[u]:
                self.parent[u] = find(self.parent[u])
            return self.parent[u]
        
        def join(u, v):
            u = find(u)
            v = find(v)
            
            if u != v:
                self.parent[u] = v
                return True
            
            return False
        
        for i, q in enumerate(queries):
            q.append(i)
        
        edgeList.sort(key = lambda w : w[2])
        queries.sort(key = lambda w : w[2])
        
        i, m = 0, len(queries)
        n = len(edgeList)
        res = [False for _ in range(m)]
        
        for q in queries:
            while i < n and edgeList[i][2] < q[2]:
                join(edgeList[i][0], edgeList[i][1])
                i += 1
            if find(q[0]) == find(q[1]):
                res[q[3]] = True
                
        return res