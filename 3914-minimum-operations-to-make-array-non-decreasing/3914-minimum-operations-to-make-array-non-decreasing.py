class Solution(object):
    def minOperations(self, nums):
        n = len(nums)
        add = [0] * n
        
        for i in range(1, n):
            add[i] = max(0, add[i-1] - (nums[i] - nums[i-1]))
        
        cost = add[0]  # = 0
        for i in range(1, n):
            cost += max(0, add[i] - add[i-1])
        
        return cost
        