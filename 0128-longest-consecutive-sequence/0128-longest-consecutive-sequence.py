class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        setNums = set(nums)
        ans = 0
        
        for num in nums:
            if num - 1 not in setNums:
                step = num + 1
                while step in setNums:
                    step += 1
                ans = max(ans, step - num)
                
        return ans