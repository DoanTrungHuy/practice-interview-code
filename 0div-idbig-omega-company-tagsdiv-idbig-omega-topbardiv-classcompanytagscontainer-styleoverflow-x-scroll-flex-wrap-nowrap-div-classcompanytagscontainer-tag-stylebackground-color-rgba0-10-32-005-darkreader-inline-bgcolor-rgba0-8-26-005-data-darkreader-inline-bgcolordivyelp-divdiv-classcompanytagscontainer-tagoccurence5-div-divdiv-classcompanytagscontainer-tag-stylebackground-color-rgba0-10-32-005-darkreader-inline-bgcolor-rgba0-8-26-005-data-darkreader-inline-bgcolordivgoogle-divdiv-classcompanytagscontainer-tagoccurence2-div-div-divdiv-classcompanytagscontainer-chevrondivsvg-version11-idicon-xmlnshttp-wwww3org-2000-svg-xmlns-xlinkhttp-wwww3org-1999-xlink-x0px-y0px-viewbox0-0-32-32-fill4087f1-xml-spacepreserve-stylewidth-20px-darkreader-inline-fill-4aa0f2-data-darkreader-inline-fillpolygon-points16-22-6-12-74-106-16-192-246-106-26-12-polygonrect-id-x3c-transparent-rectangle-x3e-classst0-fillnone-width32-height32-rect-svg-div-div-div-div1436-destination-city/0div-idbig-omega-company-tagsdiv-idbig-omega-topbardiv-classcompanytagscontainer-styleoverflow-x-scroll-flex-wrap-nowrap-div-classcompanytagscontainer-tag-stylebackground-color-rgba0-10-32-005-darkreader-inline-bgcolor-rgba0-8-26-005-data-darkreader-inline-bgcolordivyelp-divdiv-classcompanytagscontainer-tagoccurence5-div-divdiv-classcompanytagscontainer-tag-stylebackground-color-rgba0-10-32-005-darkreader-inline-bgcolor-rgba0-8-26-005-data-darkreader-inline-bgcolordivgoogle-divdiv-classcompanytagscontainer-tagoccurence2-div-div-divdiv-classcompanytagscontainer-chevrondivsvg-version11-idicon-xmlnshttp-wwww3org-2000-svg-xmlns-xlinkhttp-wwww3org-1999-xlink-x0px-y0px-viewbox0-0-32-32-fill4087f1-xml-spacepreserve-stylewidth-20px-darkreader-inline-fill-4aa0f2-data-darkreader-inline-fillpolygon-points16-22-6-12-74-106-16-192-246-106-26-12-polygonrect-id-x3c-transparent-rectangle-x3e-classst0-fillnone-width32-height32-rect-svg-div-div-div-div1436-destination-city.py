class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        flag = defaultdict(bool)
        
        for a, b in paths:
            flag[a] = True
            
        for a, b in paths:
            if flag[b] == False:
                return b
            
        return ""