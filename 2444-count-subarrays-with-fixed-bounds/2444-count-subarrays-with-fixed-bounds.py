class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        iMin = -1
        iMax = -1
        jExc = -1
        n = len(nums)
        cnt = 0
        
        for i in range(n):
            if nums[i] < minK or nums[i] > maxK:
                jExc = i
            if nums[i] == minK:
                iMin = i
            if nums[i] == maxK:
                iMax = i
            cnt += max(0, min(iMin, iMax) - jExc)
                
        return cnt