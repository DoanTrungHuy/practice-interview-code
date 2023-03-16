class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        
        for u, v in prerequisites:
            adj[u].append(v)
        
        color = [0] * numCourses
        
        def dfs(u: int) -> bool:
            if color[u] == 1:
                return False
            color[u] = 1
            for v in adj[u]:
                if color[v] == 0:
                    if not dfs(v):
                        return False
                elif color[v] == 1:
                    return False
            color[u] = 2
            return True
        
        for u in range(0, numCourses):
            if color[u] == 0 and not dfs(u):
                return False
        
        return True