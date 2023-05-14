class Solution:
    def searchMinimum(self, nums, left, right):
        while left <= right:
            mid = left + (right - left) // 2
            if (mid == left or nums[mid - 1] > nums[mid]) and (mid == right or nums[mid + 1] > nums[mid]):
                return mid
            elif nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    def binarySearch(self, nums, left, right, target):
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        pivot = self.searchMinimum(nums, 0, n - 1)
        res = self.binarySearch(nums, 0, pivot - 1, target)
        if res != -1:
            return res
        return self.binarySearch(nums, pivot, n - 1, target)