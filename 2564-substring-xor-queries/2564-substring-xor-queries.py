class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        ans = []
        
        for a, b in queries:
            val = a ^ b
            val = bin(val)[2:]
            if val in s:
                ans.append([s.index(val) , s.index(val) + len(val) - 1])
            else:
                ans.append([-1,-1])
                
        return ans if ans else [[-1,-1]]