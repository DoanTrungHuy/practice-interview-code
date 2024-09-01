from collections import Counter

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        half = (n + 1) // 2
        visited = set()
        
        fact = [1 for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i
        print(fact)
        ans = 0

        for num in range(10**(half - 1), 10**half):
            s = str(num)
            s = s + s[::-1][n&1:]
            id_s = ''.join(sorted(s))
            
            if int(s) % k == 0 and id_s not in visited:
                freq = Counter(s)
                curr_ans = (n - freq['0']) * fact[n - 1]
                for v in freq.values():
                    curr_ans //= fact[v]
                ans += curr_ans
                visited.add(id_s)
            
        return ans
