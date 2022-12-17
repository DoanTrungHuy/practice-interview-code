class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        res = 0
        
        for token in tokens:
            if token not in "+-*/":
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                    
                c = 0
                
                if token == '+':
                    c = a + b
                elif token == '-':
                    c = a - b
                elif token == '/':
                    c = int(a / b)
                else:
                    c = a * b
                    
                stack.append(c)

        return stack.pop()