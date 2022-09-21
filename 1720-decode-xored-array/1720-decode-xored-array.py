class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        res = [first]
        n = len(encoded)
        
        for i in range(1, n + 1):
            res += [res[i - 1] ^ encoded[i - 1]]
            
        return res
            