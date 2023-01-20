class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = set()
        
        for mask in range(1, 1 << n):
            tmp = []
            flag = True
            for i in range(n):
                bit = n - i - 1
                if (mask >> bit) & 1:
                    if not tmp:
                        tmp.append(nums[i])
                    elif nums[i] >= tmp[-1]:
                        tmp.append(nums[i])
                    else:
                        flag = False
                        break
            if len(tmp) >= 2 and flag:
                ans.add(tuple(tmp))
                
        return ans  