class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n, m = len(mat), len(mat[0])
        tmp = []
        
        for i in range(n):
            tmp.append((mat[i].count(1), i))
            
        tmp.sort()
        ans = []
        for cnt, idx in tmp:
            ans.append(idx)
            
        return ans[:k]