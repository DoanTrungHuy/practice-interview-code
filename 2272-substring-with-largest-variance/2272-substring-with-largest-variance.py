class Solution:
    def largestVariance(self, s: str) -> int:
        cnt = Counter(s)
        res = 0
        per = permutations(cnt, 2)
        
        for a, b in per:
            maxSub = 0
            remain_a, remain_b = cnt[a], cnt[b]
            has_a, has_b = False, False
            
            for c in s:
                if c != a and c != b:
                    continue
                    
                if remain_a == 0 and remain_b == 0:
                    break
                    
                if maxSub < 0 and remain_a != 0 and remain_b != 0:
                    maxSub = 0
                    has_a, has_b = False, False
                    
                if c == a:
                    maxSub += 1
                    remain_a -= 1
                    has_a = True
                    
                if c == b:
                    maxSub -= 1
                    remain_b -= 1
                    has_b = True
                    
                if has_a and has_b:
                    res = max(res, maxSub)
            
        return res