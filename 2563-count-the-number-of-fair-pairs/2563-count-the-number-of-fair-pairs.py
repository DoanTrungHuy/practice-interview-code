from sortedcontainers import SortedList

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        ans = 0
        sl = SortedList()
        
        for i, num in enumerate(nums):
            ans += sl.bisect_right(upper - nums[i]) - sl.bisect_left(lower - nums[i])
            sl.add(num)
        
        return ans