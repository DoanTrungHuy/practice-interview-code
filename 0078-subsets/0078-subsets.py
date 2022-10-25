class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)
        
        for mask in range(1 << n):
            tmp = []
            
            for i in range(n):
                if not (mask >> i) & 1:
                    continue    
                tmp += [nums[i]]
            
            ans += [tmp]
            
        
        return ans