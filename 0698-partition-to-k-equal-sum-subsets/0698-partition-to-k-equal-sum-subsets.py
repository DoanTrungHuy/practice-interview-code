class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        total = sum(nums)
        
        if total % k != 0 or n < k:
            return False
        
        d = total // k
        flags = [0] * k
        self.check = False
        nums.sort(reverse = True)
        
        def backTracking(i):
            if self.check:
                return
            
            if i == n:
                for j in range(k):
                    if flags[j] != d:
                        return
                self.check = True
                return
            
            seen = set()
            
            for j in range(k):
                if flags[j] in seen:
                    continue
                if flags[j] + nums[i] > d:
                    continue
                flags[j] += nums[i]
                backTracking(i + 1)
                flags[j] -= nums[i]
                if not flags[j]:
                    break
        
        backTracking(0)
        return self.check
                