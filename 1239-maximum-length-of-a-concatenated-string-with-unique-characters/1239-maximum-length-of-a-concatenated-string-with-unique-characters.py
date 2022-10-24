class Solution:
    def maxLength(self, arr: List[str]) -> int:
        n = len(arr)
        self.ans = 0
        
        def checkUnique(path):
            ms = set()
            for char in path:
                if char in ms:
                    return False
                ms.add(char)
            return True
        
        def backTracking(i, path):
            if not checkUnique(path):
                return
            
            if len(path) > self.ans:
                self.ans = len(path)
            
            for j in range(i, n):
                backTracking(j + 1, path + arr[j])
                
        backTracking(0, '')
        return self.ans
                
            