class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        
        ans = 0
        
        for child in range(1, children + 1):
            if money - 8 >= children - child:
                money -= 8
                ans += 1
            else:
                if money == 4 and children == child:
                    ans -= 1
                money = 0
                break
        
        if money > 0:
            ans -= 1
            
        return ans