class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        cnt = defaultdict(int)
        
        for num in nums:
            cnt[num] += 1
        
        ans = []
        
        for num, length in cnt.items():
            for _ in range(length):
                n = len(ans)
                flag = False
                for i in range(n):
                    if num not in ans[i]:
                        flag = True
                        ans[i].append(num)
                        break
                if not flag:
                    ans.append([num])
        
        return ans