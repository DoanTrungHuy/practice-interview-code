class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        
        for d in num:
            while stack and stack[-1] > d and k > 0:
                stack.pop()
                k -= 1
            stack.append(d)
            
        while stack and k > 0:
            stack.pop()
            k -= 1
            
        i = 0
        
        while i < len(stack) and stack[i] == '0':
            i += 1
            
        res = "".join(stack[i:])
        
        return res or "0"