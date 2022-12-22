class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = defaultdict(list)

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        cnt = [1] * n

        def dfs(u, parent):
            cntNode = 1
            for v in graph[u]:
                if v != parent:
                    cntNode += dfs(v, u)
            cnt[u] = cntNode
            return cntNode
        
        dfs(0, -1)
        ans = [0] * n

        def dfs2(u, parent, total):
            ans[u] = total
            for v in graph[u]:
                if v != parent:
                    dfs2(v, u, total + n - 2 * cnt[v])
    
        dfs2(0, -1, sum(cnt[1:]))
        return ans