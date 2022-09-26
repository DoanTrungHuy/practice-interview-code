class Solution:
    def canMeet(self, u, target, visited):
        visited[u] = True
        
        if u == target:
            return True
        
        for v in self.adj[u]:
            if visited[v]:
                continue
            if self.canMeet(v, target, visited):
                return True
            
        return False
        
    def equationsPossible(self, equations: List[str]) -> bool:
        self.adj = defaultdict(set)
        
        for equation in equations:
            u, v = equation[0], equation[3]
            if equation[1] == '=':
                self.adj[u].add(v)
                self.adj[v].add(u)
        
        for equation in equations:
            if equation[1] == '!':
                u, v = equation[0], equation[3]
                if self.canMeet(u, v, defaultdict(bool)):
                    return False
                
        return True