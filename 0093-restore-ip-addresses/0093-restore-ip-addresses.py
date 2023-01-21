class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []
        
        def backTracking(s: str, sizeIP: int, path: str):
            if sizeIP > 4:
                return
            if sizeIP == 4:
                if not s:
                    res.append(path[:-1])
                return
            for i in range(1, len(s) + 1):
                if s[:i] == '0' or (s[0] != '0' and 0 < int(s[:i]) < 256):
                    backTracking(s[i:], sizeIP + 1, path + s[:i] + '.')
                    
        backTracking(s, 0, '')
        return res