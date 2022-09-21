class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        hashMap = defaultdict(list)
        n, m = len(mat), len(mat[0])
        
        for i in range(n):
            for j in range(m):
                hashMap[i - j].append(mat[i][j])
                
        for key in hashMap:
            hashMap[key].sort(reverse = True)
            
        for i in range(n):
            for j in range(m):
                mat[i][j] = hashMap[i - j].pop()
                
        return mat