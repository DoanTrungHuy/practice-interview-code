class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        total = sum(nums)
        
        if total % k != 0 or n < k:
            return False
        
        d = total // k
        flags = [0] * k
        nums.sort(reverse = True)
        
        def backTracking(i):
            if i == n:
                return True
            
            seen = set()
            
            for j in range(k):
                if flags[j] in seen:
                    continue
                if flags[j] + nums[i] <= d:
                    seen.add(flags[j])
                    flags[j] += nums[i]
                    if backTracking(i + 1):
                        return True
                    flags[j] -= nums[i]
                    
            return False
        
        return backTracking(0)
                