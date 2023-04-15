class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        ma = nums[0]
        ans = [0]
        
        for num in nums:
            ma = max(ma, num)
            ans.append(ans[-1] + num + ma)
            
        return ans[1:]