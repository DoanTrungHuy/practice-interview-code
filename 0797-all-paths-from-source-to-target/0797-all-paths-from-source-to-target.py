class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        n = len(graph)

        def dfs(u: int, path: List[int]) -> None:
            if u == n - 1:
                ans.append(path)
                return
            for v in graph[u]:
                dfs(v, path + [v])

        dfs(0, [0])

        return ans