class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        ans, n, prefix = [], len(nums), [0] + list(accumulate(nums))
        for x in queries:
            i, j = bisect_left(nums, x), bisect_right(nums, x)
            ans.append(x * i - prefix[i] + prefix[n] - prefix[j] - x * (n - j))
        return ans