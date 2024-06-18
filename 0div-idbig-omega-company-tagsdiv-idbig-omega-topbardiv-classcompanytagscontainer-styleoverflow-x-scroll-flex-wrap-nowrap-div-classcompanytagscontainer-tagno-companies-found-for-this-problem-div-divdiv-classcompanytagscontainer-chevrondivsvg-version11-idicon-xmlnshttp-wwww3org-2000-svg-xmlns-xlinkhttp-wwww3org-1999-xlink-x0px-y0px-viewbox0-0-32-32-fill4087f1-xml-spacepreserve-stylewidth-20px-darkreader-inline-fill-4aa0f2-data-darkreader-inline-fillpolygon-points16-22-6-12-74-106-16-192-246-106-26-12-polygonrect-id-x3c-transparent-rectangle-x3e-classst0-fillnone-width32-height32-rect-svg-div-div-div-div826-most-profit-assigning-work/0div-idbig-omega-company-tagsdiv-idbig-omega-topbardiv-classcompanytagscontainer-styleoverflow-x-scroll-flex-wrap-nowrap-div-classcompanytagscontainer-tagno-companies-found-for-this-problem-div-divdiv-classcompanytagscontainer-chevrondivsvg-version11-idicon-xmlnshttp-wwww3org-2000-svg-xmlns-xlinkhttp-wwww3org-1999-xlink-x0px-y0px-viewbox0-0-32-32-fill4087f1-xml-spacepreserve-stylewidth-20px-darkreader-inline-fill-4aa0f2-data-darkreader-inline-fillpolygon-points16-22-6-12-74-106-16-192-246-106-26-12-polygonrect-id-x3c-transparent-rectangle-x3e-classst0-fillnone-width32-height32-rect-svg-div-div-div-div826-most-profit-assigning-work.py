class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(list(zip(difficulty, profit)))
        n = len(worker)
        best = 0
        ans = 0
        i = 0
        
        for ability in sorted(worker):
            while i < n and ability >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            ans += best
        
        return ans