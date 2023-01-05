class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = set()
        
        for i in range(n - 2):
            l, r = i + 1, n - 1
            target = -nums[i]
            
            while l < r:
                total = nums[l] + nums[r]
                if total == target:
                    ans.add((nums[i], nums[l], nums[r]))
                    r -= 1
                    l += 1
                elif total > target:
                    r -= 1
                else:
                    l += 1
                    
        return ans