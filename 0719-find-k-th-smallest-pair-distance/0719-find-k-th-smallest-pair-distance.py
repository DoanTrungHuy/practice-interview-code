class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        left, right = 0, 10**9
        ans = right
        
        def get_len(diff):
            glen = 0
            j = 0
            
            for i in range(n):
                while nums[i] - nums[j] > diff:
                    j += 1
                glen += i - j
            
            return glen
                
        
        while left <= right:
            mid = (left + right) // 2
            
            if get_len(mid) < k:
                left = mid + 1
            else:
                ans = mid
                right = mid - 1
                
        return ans