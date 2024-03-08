class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        max_element = max(cnt.values())
        total = 0
        
        for x in cnt.values():
            total += x == max_element
            
        return total * max_element