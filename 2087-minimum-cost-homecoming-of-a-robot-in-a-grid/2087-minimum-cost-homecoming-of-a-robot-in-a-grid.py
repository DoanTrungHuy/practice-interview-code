class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        si, sj = startPos
        ei, ej = homePos
        
        ans = 0
        
        step = -1 if sj < ej else 1
        
        while sj != ej:
            ans += colCosts[ej]
            ej += step
            
        step = -1 if si < ei else 1
        
        while si != ei:
            ans += rowCosts[ei]
            ei += step
            
        return ans