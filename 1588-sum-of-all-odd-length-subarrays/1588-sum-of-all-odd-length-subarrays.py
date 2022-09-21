class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        s = 0
        
        for i in range(1, n + 1, 2):
            for j in range(0, n - i + 1):
                s += sum(arr[j:j + i])
                
        return s