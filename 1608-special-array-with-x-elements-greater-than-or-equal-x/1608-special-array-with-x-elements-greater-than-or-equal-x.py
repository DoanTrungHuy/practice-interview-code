class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for x in range(0, 1001):
            cnt = 0
            for num in nums:
                if num >= x:
                    cnt += 1
            if x == cnt:
                return x
        return -1