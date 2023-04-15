class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.n = n
        self.adj = defaultdict(list)
        
        for u, v, w in edges:
            self.adj[u].append((v, w))

    def addEdge(self, edge: List[int]) -> None:
        u, v, w = edge
        self.adj[u].append((v, w))

    def shortestPath(self, node1: int, node2: int) -> int:
        dist = [inf for _ in range(self.n)]
        pq = [(0, node1)]
        dist[node1] = 0
        
        while pq:
            du, u = heappop(pq)
            
            for v, w in self.adj[u]:
                if du + w < dist[v]:
                    dist[v] = du + w
                    heappush(pq, (dist[v], v))
                    
        return -1 if dist[node2] == inf else dist[node2]


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)