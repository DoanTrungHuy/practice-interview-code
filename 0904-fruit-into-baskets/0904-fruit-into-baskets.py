class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        h = defaultdict(int)
        j, n = 0, len(fruits)
        ans = 0
        
        for i in range(n):
            h[fruits[i]] += 1
            while len(h) > 2:
                h[fruits[j]] -= 1
                if h[fruits[j]] == 0:
                    del h[fruits[j]]
                j += 1
            ans = max(ans, i - j + 1)
            
        return ans