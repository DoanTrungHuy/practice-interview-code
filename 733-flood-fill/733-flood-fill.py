class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        n, m = len(image), len(image[0])
        flag = image[sr][sc]
        DIR = [1, 0, -1, 0, 1]
        
        def dfs(x, y):
            if x < 0 or x == n or y < 0 or y == m or image[x][y] == color or image[x][y] != flag:
                return
            image[x][y] = color
            
            for i in range(4):
                dfs(x + DIR[i], y + DIR[i + 1])
            
        dfs(sr, sc)
        return image