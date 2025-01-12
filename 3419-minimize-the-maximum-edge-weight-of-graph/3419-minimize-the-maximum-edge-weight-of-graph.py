from collections import defaultdict, deque

class Solution:
    def __init__(self):
        self.n = 0
        self.threshold = 0
        self.edges = []

    def bfs(self, n, i_adj):
        mq = deque([0])
        visited = [False] * n
        visited[0] = True

        while mq:
            u = mq.popleft()
            for v in i_adj[u]:
                if not visited[v]:
                    visited[v] = True
                    mq.append(v)

        return all(visited)

    def f(self, m):
        i_adj = defaultdict(list)
        adj = defaultdict(list)

        for edge in self.edges:
            u, v, w = edge
            if w <= m:
                i_adj[v].append(u)
                if len(adj[u]) < self.threshold:
                    adj[u].append(w)

        if not self.bfs(self.n, i_adj):
            return False

        for ws in adj.values():
            if len(ws) > self.threshold:
                return False

        return True

    def minMaxWeight(self, n, edges, threshold):
        self.n = n
        self.threshold = threshold
        self.edges = edges

        max_w = max(edge[2] for edge in edges)

        left, right = 1, max_w
        ans = -1

        while left <= right:
            mid = (left + right) // 2
            if self.f(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans
