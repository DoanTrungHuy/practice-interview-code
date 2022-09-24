class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        n, m = len(arr1), len(arr2)
        cnt = 0

        for i in range(n):
            flag = True
            for j in range(m):
                if abs(arr1[i] - arr2[j]) <= d:
                    flag = False
                    break
            cnt += int(flag)
        
        return cnt