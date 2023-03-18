class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if children > money:
            return -1
        
        if money < 8:
            return 0
        
        divM = money // 8
        mod = money % 8
        
        if divM == children and mod == 0: 
            return children
        
        if divM >= children: 
            return children - 1
        
        if mod == 4 and (children - divM) == 1: 
            return children - 2
        
        if mod >= (children - divM): 
            return divM
        
        left = children - divM
        
        while mod < left:
            left += 1
            mod += 8
            divM -= 1
            
        return divM