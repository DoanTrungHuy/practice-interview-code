class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        dp = [[0 for _ in range(3)] for _ in range(11)]
        
        nums = list(map(int, list(str(n))))
        digits = list(map(int, digits))
        
        for d in digits:
            states = 0
            if d == nums[0]:
                states = 1
            elif d > nums[0]:
                states = 2
            dp[1][states] += 1
        
        sz = len(nums)
        
        for i in range(1, sz):
            for states in range(3):
                if dp[i][states] == 0:
                    continue
                for d in digits:
                    newStates = states
                    if states == 1:
                        if d > nums[i]:
                            newStates = 2
                        elif d < nums[i]:
                            newStates = 0
                    dp[i + 1][newStates] += dp[i][states]
                    
        ans = 0
        
        for i in range(sz + 1):
            szStates = 1 if i == sz else 2
            for states in range(szStates + 1):
                ans += dp[i][states]
                
        return ans