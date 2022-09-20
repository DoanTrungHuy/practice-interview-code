class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        hashMap = {}
        
        for i in range(n):
            if target - nums[i] in hashMap:
                return [hashMap[target - nums[i]], i]
            hashMap[nums[i]] = i
        
        return []