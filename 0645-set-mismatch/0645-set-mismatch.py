class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        hashMap = Counter(nums)
        n = len(nums)
        s = 0
        ans = []
        
        for key in hashMap:
            s += key
            if hashMap[key] > 1:
                ans.append(key)
                
        ans.append(n * (n + 1) // 2 - s)
        
        return ans
            