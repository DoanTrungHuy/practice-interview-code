class Solution:
     def distinctNames(self, A: List[str]) -> int:
         m, A, s = defaultdict(Counter), set(A), ascii_lowercase
         for w in A:
             for x in s:
                 if x + w[1:] not in A: m[x][w[0]] += 1
         return sum(m[w[0]][x] if x + w[1:] not in A else 0 for x in s for w in A)