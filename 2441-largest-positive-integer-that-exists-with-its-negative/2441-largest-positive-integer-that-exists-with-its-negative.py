class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        hashMap = {}
        
        for num in nums:
            hashMap[num] = True
            
        nums.sort(reverse = True)
        
        for num in nums:
            if -num in hashMap:
                return num
        
        return -1