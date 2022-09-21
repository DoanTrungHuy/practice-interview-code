class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        temp = sorted(nums)
        hashMap = {}
        n = len(nums)
        
        for i in range(n):
            if temp[i] not in hashMap:
                hashMap[temp[i]] = i
                
        return [hashMap[num] for num in nums]