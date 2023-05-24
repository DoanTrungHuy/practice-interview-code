class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        line = defaultdict(int)
        
        for start, end, color in segments:
            line[start] += color
            line[end] -= color
        
        res = []
        start, total = 0, 0
        
        for end in sorted(line.keys()):
            if total > 0:
                res.append([start, end, total])
            total += line[end]
            start = end
            
        return res