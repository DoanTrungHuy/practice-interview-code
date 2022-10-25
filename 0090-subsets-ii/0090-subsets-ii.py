class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        n = len(nums)
        seen = set()
        
        for mask in range(1 << n):
            tmp = []
            s = ''
            
            for i in range(n):
                if not (mask >> i) & 1:
                    continue    
                tmp += [nums[i]]
                s += str(nums[i])
                
            if s not in seen:
                ans += [tmp]
                seen.add(s)
        
        return ans