class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        subset = sorted(nums)[-k:]
        ans = []
        for num in nums:
            if num in subset:
                ans.append(num)
                subset.remove(num)
        return ans