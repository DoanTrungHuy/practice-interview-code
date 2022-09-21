class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        n = len(nums)
        m = n // 2
        
        ans = []
        
        for i in range(m):
            ans.append(nums[i])
            ans.append(nums[m + i])
        
        return ans