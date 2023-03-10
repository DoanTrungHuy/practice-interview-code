class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        ans = set()
        sumCandi = sum(candidates)
        
        def dfs(i, s, path):
            if s == target:
                ans.add(tuple(path))
                return
            if i == n or s > target:
                return
            for j in range(i, n):
                if j > i and candidates[j - 1] == candidates[j]:
                    continue
                dfs(j + 1, s + candidates[j], path + [candidates[j]])
                
        dfs(0, 0, [])
        
        return ans