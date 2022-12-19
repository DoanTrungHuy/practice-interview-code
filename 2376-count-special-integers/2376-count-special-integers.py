class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        dp = [[[0 for _ in range(3)] for _ in range(1 << 10)] for _ in range(11)]
        nums = list(map(int, list(str(n))))
        sz = len(nums)
        
        for d in range(1, 10):
            states = 0
            if d == nums[0]:
                states = 1
            elif d > nums[0]:
                states = 2
            dp[1][1 << d][states] += 1
            
        for i in range(1, sz):
            for mask in range(1, (1 << 10)):
                for states in range(3):
                    if dp[i][mask][states] == 0:
                        continue
                    for d in range(10):
                        if mask & (1 << d) > 0:
                            continue
                        newMask = mask | (1 << d)
                        newStates = states
                        if states == 1:
                            if d < nums[i]:
                                newStates = 0
                            elif d > nums[i]:
                                newStates = 2
                        dp[i + 1][newMask][newStates] += dp[i][mask][states]
            
        ans = 0
        
        for i in range(1, sz + 1):
            for mask in range(1, (1 << 10)):
                szStates = 1 if i == sz else 2
                for states in range(szStates + 1):
                    ans += dp[i][mask][states]
                    
        return ans