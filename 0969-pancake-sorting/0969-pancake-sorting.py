class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = []
        
        for i in range(n):
            j = arr.index(max(arr[:n - i]))
            
            arr[:j + 1] = arr[:j + 1][::-1]
            
            ans.append(j + 1)
            
            arr[:n - i] = arr[:n - i][::-1]
            
            ans.append(n - i)
            
        return ans