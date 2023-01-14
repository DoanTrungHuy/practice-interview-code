class Solution:
    def mergeSort(self, nums: List[int]) -> None:
        if len(nums) <= 1:
            return
        
        mid = len(nums) // 2
        nums1 = nums[:mid]
        nums2 = nums[mid:]

        self.mergeSort(nums1)
        self.mergeSort(nums2)

        i = j = k = 0
        n, m = len(nums1), len(nums2)

        while i < n and j < m:
            if nums1[i] < nums2[j]:
                nums[k] = nums1[i]
                i += 1
            else:
                nums[k] = nums2[j]
                j += 1
            k += 1
            
        while i < n:
            nums[k] = nums1[i]
            i += 1
            k += 1
            
        while j < m:
            nums[k] = nums2[j]
            j += 1
            k += 1
                
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums)
        return nums