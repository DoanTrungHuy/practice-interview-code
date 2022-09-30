class Solution:
    def binarySearch(self, arr, target):
        l, r = 0, len(arr) - 1
        while l <= r:
            m = l + (r - l) // 2
            if arr[m] == target:
                l = m + 1
            else:
                r = m - 1
        return l
                
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n, m = len(mat), len(mat[0])
        tmp = []
        
        for i in range(n):
            tmp.append((self.binarySearch(mat[i], 1), i))
            
        tmp.sort()
        ans = []
        for cnt, idx in tmp:
            ans.append(idx)
            
        return ans[:k]