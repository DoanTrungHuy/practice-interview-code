class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        
        def dfs(i, j, s):
            if i == n and j == n:
                ans.append(s)
                return
            if i < n:
                dfs(i + 1, j, s + '(')
            if j < i:
                dfs(i, j + 1, s + ')')
            
        dfs(0, 0, "")
        return ans