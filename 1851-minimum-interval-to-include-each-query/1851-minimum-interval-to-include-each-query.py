from sortedcontainers import SortedList, SortedSet, SortedDict

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        line = defaultdict(SortedSet)
        
        for start, end in intervals:
            line[start].add((1, end - start + 1))
            line[end + 1].add((2, end - start + 1))
            
        for i, time in enumerate(queries):
            line[time].add((3, i))
            
        line = SortedDict(line)
        
        sizes = SortedList()
        m = len(queries)
        ans = [-1 for _ in range(m)]
        
        for time in line:
            for choose, size_or_index in line[time]:
                if choose == 1:
                    sizes.add(size_or_index)
                elif choose == 2:
                    sizes.remove(size_or_index)
                elif choose == 3:
                    if sizes:
                        ans[size_or_index] = sizes[0]
                        
        return ans