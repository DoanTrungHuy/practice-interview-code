class Solution:
    def search(self, nums: List[int], target: int) -> int:
        hashMap = {}
        n = len(nums)
        
        for i in range(n):
            hashMap[nums[i]] = i
        
        nums.sort()
        
        l, r = 0, n - 1
        
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] == target:
                return hashMap[nums[m]]
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1
                
        return -1