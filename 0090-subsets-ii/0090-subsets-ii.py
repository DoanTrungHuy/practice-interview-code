class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        n = len(nums)
        
        for mask in range(1 << n):
            tmp = []
            s = ''
            
            for i in range(n):
                if not (mask >> i) & 1:
                    continue    
                tmp += [nums[i]]
                
            if tmp not in ans:
                ans += [tmp]
        
        return ans