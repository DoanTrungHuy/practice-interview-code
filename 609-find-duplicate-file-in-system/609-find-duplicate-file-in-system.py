class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        hashMap = defaultdict(list)
        
        for path in paths:
            directory, *files = path.split()
            
            for file in files:
                file = file[:-1]
                fileName, content = file.split('(')
                hashMap[content].append(directory + '/' + fileName)
                
        return [listPath for listPath in hashMap.values() if len(listPath) > 1]