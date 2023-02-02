class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        prefSum = [0] * n
        prefSum[0] = arr[0]
        
        for i in range(1, n):
            prefSum[i] = prefSum[i - 1] ^ arr[i]
            
        ans = []
        for a, b in queries:
            if a == 0:
                ans.append(prefSum[b])
            else:
                ans.append(prefSum[b] ^ prefSum[a - 1])
            
        return ans