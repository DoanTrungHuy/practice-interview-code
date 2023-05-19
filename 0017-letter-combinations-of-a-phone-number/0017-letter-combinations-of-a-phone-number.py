class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        n = len(digits)
        d = dict()
        c = 'a'
        step = 3
        
        for i in range(2, 10):
            string = ""
            if i == 7 or i == 9:
                step = 4
            else:
                step = 3
            for _ in range(step):
                string += c
                c = chr(ord(c) + 1)
            d[str(i)] = string
        
        self.ans = []
        
        def dfs(i, path):
            if i == n:
                self.ans.append(path)
                return
            for c in d[digits[i]]:
                dfs(i + 1, path + c)
               
        dfs(0, "")
        return self.ans