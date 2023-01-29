class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        visited = [False for _ in range(n)]
        
        for _, v in edges:
            visited[v] = True
            
        ans = []
        
        for u in range(n):
            if not visited[u]:
                ans.append(u)
                
        return ans