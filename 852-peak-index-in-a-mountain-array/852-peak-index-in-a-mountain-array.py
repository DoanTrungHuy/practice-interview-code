class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        n = len(arr)
        l, r = 1, n - 2
        
        while l <= r:
            m = l + (r - l) // 2
            
            if arr[m - 1] < arr[m] < arr[m + 1]:
                l = m + 1
            elif arr[m - 1] > arr[m] > arr[m + 1]:
                r = m - 1
            else:
                return m
        
        return -1