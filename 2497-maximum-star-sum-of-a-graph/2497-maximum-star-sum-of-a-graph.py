class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        adj = defaultdict(list)
        n = len(vals)
        
        for u, v in edges:
            if vals[u] > 0:
                adj[v].append(u)
            if vals[v] > 0:
                adj[u].append(v)
                
        maxSum = -inf
        
        for u in range(n):
            maxSum = max(maxSum, vals[u] + sum(sorted([vals[v] for v in adj[u]])[::-1][:k]))
            
        return maxSum