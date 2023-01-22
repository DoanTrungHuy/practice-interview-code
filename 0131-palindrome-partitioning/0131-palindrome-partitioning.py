class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        
        def backTracking(s: str, path: List[str]) -> None:
            if not s:
                res.append(path)
                return
            for i in range(1, len(s) + 1):
                if s[:i] == s[:i][::-1]:
                    backTracking(s[i:], path + [s[:i]])
                
        backTracking(s, [])
        
        return res