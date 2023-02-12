class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        ans = []
        
        for a, b in queries:
            val = a ^ b
            val = bin(val)[2:]
            if val in s:
                i = s.index(val)
                k = len(val)
                ans.append([i , i + k - 1])
            else:
                ans.append([-1,-1])
                
        return ans