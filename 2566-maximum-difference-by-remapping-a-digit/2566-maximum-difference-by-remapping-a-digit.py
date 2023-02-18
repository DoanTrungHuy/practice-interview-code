class Solution:
    def minMaxDifference(self, num: int) -> int:
        num = str(num)
        n = len(num)
        flag = num[0]
        
        for i in range(n):
            if num[i] != '9':
                flag = num[i]
                break
            
        return int(num.replace(flag, '9')) - int(num.replace(num[0], '0'))