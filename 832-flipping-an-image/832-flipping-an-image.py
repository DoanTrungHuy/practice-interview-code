class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n, m = len(image), len(image[0])
        
        for i in range(n):
            image[i] = image[i][::-1]
            for j in range(m):
                image[i][j] = int(not image[i][j])
                
        return image