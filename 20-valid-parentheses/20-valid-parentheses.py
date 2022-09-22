class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        hashMap = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        
        for char in s:
            if char in hashMap:
                stack.append(char)
            else:
                if len(stack):
                    key = stack.pop()
                    if hashMap[key] != char:
                        return False
                elif len(stack) == 0:
                    return False
                
        return len(stack) == 0