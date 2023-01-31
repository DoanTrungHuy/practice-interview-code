class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        d = 0
        n = len(nums)
        
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                d = i
                break
            if nums[i] == target:
                return True
                
        def binarySearch(l: int, r: int) -> bool:
            while l <= r:
                m = (l + r) // 2
                if nums[m] == target:
                    return True
                elif nums[m] < target:
                    l = m + 1
                else:
                    r = m - 1
            return False
        
        return binarySearch(0, d) or binarySearch(d + 1, n - 1)