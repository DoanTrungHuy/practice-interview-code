class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        nums[:] = nums[::-1]
        nums[:k % n] = nums[:k % n][::-1]
        nums[k % n:] = nums[k % n:][::-1]
        