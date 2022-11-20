class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        cnt = 0
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if nums[i] != nums[j] and nums[i] != nums[k] and nums[j] != nums[k]:
                        cnt += 1
                        
        return cnt