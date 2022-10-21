class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0, 1]
        
        for i in range(1, n):
            n = len(res)
            for j in range(n - 1, -1, -1):
                res.append(res[j] | 1 << i)
                
        return res