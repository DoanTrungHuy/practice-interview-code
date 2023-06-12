class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        
        c = nums[0]
        ans = []
        tmp = []
        
        for num in nums:
            if num == nums[0] or c + 1 == num:
                tmp.append(str(num))
            else:
                ans.append(tmp)
                tmp = [str(num)]
            c = num
        
        if tmp:
            ans.append(tmp)
        
        for i in range(len(ans)):
            if len(ans[i]) > 1:
                ans[i] = ans[i][0] + '->' + ans[i][-1]
            else:
                ans[i] = ans[i][0]
        
        return ans