class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [False] * n
        stack = []
        
        for i in range(n):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack:
                    dp[stack.pop()] = True
                    dp[i] = True
        
        cnt = 0
        maxLen = 0
        
        for flag in dp:
            if flag:
                cnt += 1
                maxLen = max(maxLen, cnt)
            else:
                cnt = 0
                
        return maxLen