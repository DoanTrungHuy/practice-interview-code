class DSU:
    def __init__(self, n: int) -> None:
        self.parent = [u for u in range(n + 1)]
        self.size = n
        self.group = n
    
    def find(self, u: int) -> int:
        if u != self.parent[u]:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
    def union(self, u: int, v: int) -> bool:
        u = self.find(u)
        v = self.find(v)
        if u != v:
            self.parent[u] = v
            self.group -= 1
            return True
        return False

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        Alice, Bob = DSU(n), DSU(n)
        connect_edge = 0
        
        for edge in edges:
            type_path, u, v = edge
            if type_path == 3:
                connect_edge += int(Alice.union(u, v) | Bob.union(u, v))
        
        for edge in edges:
            type_path, u, v = edge
            if type_path == 1:
                connect_edge += Alice.union(u, v)
            elif type_path == 2:
                connect_edge += Bob.union(u, v)
                
        if Alice.group == Bob.group == 1:
            return len(edges) - connect_edge
        
        return -1 