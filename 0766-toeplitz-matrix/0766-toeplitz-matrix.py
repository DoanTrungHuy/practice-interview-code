class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        hm = defaultdict(set)
        n, m = len(matrix), len(matrix[0])
        
        for i in range(n):
            for j in range(m):
                hm[i - j].add(matrix[i][j])
                if len(hm[i - j]) == 2:
                    return False
        
        return True