class Solution(object):
    def maxSumRangeQuery(self, nums, requests):
        """
        :type nums: List[int]
        :type requests: List[List[int]]
        :rtype: int
        """
        n = len(nums)
        freq = [0]*n

        for start, end in requests:
            freq[start] += 1
            if end + 1 < n:
                freq[end + 1] -= 1

        for i in range(1, n):
            freq[i] += freq[i - 1]

        freq.sort(), nums.sort()

        total = 0
        MOD = 10**9 + 7

        for i in range(n):
            total = (total + nums[i]*freq[i]) % MOD

        return total