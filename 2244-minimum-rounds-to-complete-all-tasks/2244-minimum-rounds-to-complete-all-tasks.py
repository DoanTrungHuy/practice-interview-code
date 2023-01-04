class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = defaultdict(int)
        
        for task in tasks:
            cnt[task] += 1
            
        ans = 0
            
        for key in cnt:
            if cnt[key] == 1:
                return -1    
            
            ans += cnt[key] // 3
            
            if cnt[key] % 3 != 0:
                ans += 1
            
        return ans