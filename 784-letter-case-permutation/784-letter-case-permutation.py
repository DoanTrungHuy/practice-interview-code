class Solution:
    def backTracking(self, s, path, res, i = 0):
        if len(path) == len(s):
            res.append(path)
            return
        self.backTracking(s, path + s[i], res, i + 1)
        if s[i].isalpha():
            self.backTracking(s, path + s[i].swapcase(), res, i + 1)
        
    def letterCasePermutation(self, s: str) -> List[str]:
        res = []
        self.backTracking(s, '', res)
        return res