class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        maxEle = max(arr)
        flag = [False] * (maxEle + 1)
        
        for a in arr:
            flag[a] = True
        
        for i in range(1, (maxEle + 1)):
            if flag[i] == True:
                continue
            k -= 1
            if k == 0:
                return i
            
        return maxEle + k