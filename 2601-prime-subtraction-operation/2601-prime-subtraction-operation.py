class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        maxn = max(nums)
        prime = [True for i in range(maxn + 1)]
        prime[0] = False
        prime[1] = False
        p = 2
        while (p * p <= maxn):
            if (prime[p] == True):
                for i in range(p * 2, maxn + 1, p):
                    prime[i] = False
            p += 1
            
        ohRight = []
        
        n = len(nums)
        
        for i in range(1, maxn):
            if prime[i]:
                ohRight.append(i)
                
        nums = [0] + nums
        
        ohRight = sorted(ohRight)[::-1]
        
        n += 1
        
        for i in range(1, n):
            for prime in ohRight:
                if nums[i] - prime > nums[i - 1]:
                    nums[i] = nums[i] - prime
                    break
                  
        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                return False
        
        return True