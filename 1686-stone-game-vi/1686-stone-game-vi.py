class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        tu_val = []
        n = len(aliceValues)
        
        for i in range(n):
            a = aliceValues[i]
            b = bobValues[i]
            tu_val.append((a + b, a, b))
            
        tu_val.sort()
        
        alice, bob = 0, 0
        
        for i in range(n):
            alice += tu_val[n - i - 1][1] if i % 2 == 0 else 0
            bob += tu_val[n - i - 1][2] if i % 2 == 1 else 0
            
        if alice > bob:
            return 1
        elif alice < bob:
            return -1
        
        return 0