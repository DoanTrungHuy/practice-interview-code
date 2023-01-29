class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        edges = set()
        cnt = defaultdict(int)
        
        for u, v in roads:
            edges.add((u, v))
            edges.add((v, u))
            
            cnt[u] += 1
            cnt[v] += 1
            
        ans = 0
            
        for i in range(n):
            for j in range(i + 1, n):
                ans = max(ans, cnt[i] + cnt[j] - int((i, j) in edges))
                
        return ans