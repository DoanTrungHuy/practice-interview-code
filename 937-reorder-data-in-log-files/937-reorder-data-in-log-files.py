class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digits = []
        alphas = []
        
        for log in logs:
            if log.split(' ')[1].isnumeric():
                digits.append(log)
            else:
                alphas.append(log)
                
        alphas.sort(key = lambda x : (x.split(' ')[1:], x.split(' ')[0]))
        
        return alphas + digits