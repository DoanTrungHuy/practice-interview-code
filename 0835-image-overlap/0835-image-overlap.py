class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        cnt = defaultdict(int)
        maxOverlap = 0
        n = len(img1)
        d1, d2 = [], []
        
        for i in range(n):
            for j in range(n):
                if img1[i][j] == 1:
                    d1.append((i, j))
                if img2[i][j] == 1:
                    d2.append((i, j))
                    
        for x1, y1 in d1:
            for x2, y2 in d2:
                d = ((x2 - x1), (y2 - y1))
                cnt[d] += 1
                maxOverlap = max(maxOverlap, cnt[d])
                
        return maxOverlap