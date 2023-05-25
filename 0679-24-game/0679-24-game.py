class Solution:
    def dfs(self, cards: List[int]) -> bool:
        if len(cards) == 1:
            return abs(cards[0] - 24) <= 0.0001
        
        n = len(cards)
        
        for i in range(n):
            for j in range(i + 1, n):
                a = cards[i]
                b = cards[j]
                
                dummy_cards = list(cards)
                
                dummy_cards.remove(a)                
                dummy_cards.remove(b)
                
                for val in [a + b, a - b, b - a, a * b, a / b, b / a]:
                    if val:
                        dummy_cards.append(val)
                        if self.dfs(dummy_cards):
                            return True
                        dummy_cards.pop()
                        
        return False
                    
    def judgePoint24(self, cards: List[int]) -> bool:
        return self.dfs(cards)