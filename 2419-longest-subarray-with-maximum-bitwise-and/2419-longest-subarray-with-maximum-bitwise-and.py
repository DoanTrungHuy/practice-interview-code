class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxEle = max(nums)
        maxLen = 0
        cnt = 0
        
        for num in nums:
            if num != maxEle:
                cnt = 0
            else:
                cnt += 1
                maxLen = max(maxLen, cnt)
                
        return maxLen