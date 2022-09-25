class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        left, right = 0, n - 1
        index = 0
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if letters[mid] > target:
                index = mid
                right = mid - 1
            else:
                left = mid + 1
                
        return letters[index]