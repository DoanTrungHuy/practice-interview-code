class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        visited = set()
        
        for ele in arr:
            if 2 * ele in visited or ele / 2 in visited:
                return True
            visited.add(ele)
            
        return False