class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        cnt = 0
        costs.sort()
        
        for cost in costs:
            coins -= cost
            if coins < 0:
                break
            cnt += 1
        
        return cnt