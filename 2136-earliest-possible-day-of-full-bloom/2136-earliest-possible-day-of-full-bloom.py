class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        v = []
        for i in range(len(plantTime)):
            v.append((growTime[i], plantTime[i]))
        
        v.sort(reverse = True)
        day, lpd = 0, 0
        for p in v:
            lpd += p[1]
            day = max(day, lpd + p[0])
        
        return day