class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        new = dominoes
        
        while True:
            new = new.replace('R.L', 'T')
            new = new.replace('.L', 'LL')
            new = new.replace('R.', 'RR')
            
            if new == dominoes:
                break
            else:
                dominoes = new
                
        return dominoes.replace('T', 'R.L')
        