class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        
        for i in range(n):
            pre[i + 1] = pre[i] + nums[i]
        
        diff = inf
        answ = 0
        
        for i in range(1, n + 1):
            j = n - i
            a = int(pre[i] / i)
            b = 0 if not j else int((pre[n] - pre[i]) / j)
            t = abs(a - b)
            if t < diff:
                diff = t
                answ = i - 1
                
        return answ