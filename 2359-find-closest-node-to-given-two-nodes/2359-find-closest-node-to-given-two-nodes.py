class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        
        def dfs(node: int) -> List[int]:
            dist = 0
            dp = [-1 for _ in range(n)]
            i = node
            while i != -1 and dp[i] == -1:
                dp[i] = dist
                dist += 1
                i = edges[i]
            return dp
        
        dp1 = dfs(node1)
        dp2 = dfs(node2)
        res = -1
        mini = inf
        
        for i in range(n):
            if min(dp1[i], dp2[i]) != -1 and max(dp1[i], dp2[i]) < mini:
                res = i
                mini = max(dp1[i], dp2[i])
                
        return res