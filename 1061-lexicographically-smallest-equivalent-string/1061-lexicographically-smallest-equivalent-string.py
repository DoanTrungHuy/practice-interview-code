class Solution:
    def __init__(self):
        self.parent = []
        
    def find(self, u: int) -> int:
        if u == self.parent[u]:
            return u
        return self.find(self.parent[u])
    
    def union(self, u: int, v: int) -> None:
        u = self.find(u)
        v = self.find(v)
        if u != v:
            if v < u:
                self.parent[u] = v
            else:
                self.parent[v] = u
        
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        n = len(baseStr)
        self.parent = [0 for _ in range(26)]
        
        for u in range(26):
            self.parent[u] = u
        
        for u, v in zip(s1, s2):
            self.union(ord(u) - ord('a'), ord(v) - ord('a'))
            
        return ''.join([chr(self.find(ord(char) - ord('a')) + ord('a')) for char in baseStr])