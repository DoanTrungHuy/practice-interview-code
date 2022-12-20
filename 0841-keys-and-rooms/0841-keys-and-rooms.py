class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        def dfs(u):
            visited[u] = True
            for v in rooms[u]:
                if not visited[v]:
                    dfs(v)
        dfs(0)        
        for u in range(n):
            if not visited[u]:
                return False
            
        return True