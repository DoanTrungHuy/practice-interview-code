class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        setJewel = set(jewels)
        res = 0
        
        for stone in stones:
            if stone in setJewel:
                res += 1
        return res