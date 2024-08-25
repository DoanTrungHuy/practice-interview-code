class Solution:
    def countPairs(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        
        def can_be_equal(s: str, t: str) -> bool:
            if len(s) < len(t):
                s = (len(t) - len(s))*'0' + s
            else:
                t = (len(s) - len(t))*'0' + t
            
            tmp_a, tmp_b = [], []
            
            for ai, bi in zip(s, t):
                if ai != bi:
                    tmp_a.append(ai)
                    tmp_b.append(bi)
            
            if not tmp_a and not tmp_b:
                return True
            
            if len(tmp_a) == 2 and len(tmp_b) == 2:
                return tmp_a[1] == tmp_b[0] and tmp_a[0] == tmp_b[1]
            
            return False
        
        for i in range(n):
            for j in range(i + 1, n):
                s = str(nums[i])
                t = str(nums[j])
                if can_be_equal(s, t):
                    cnt += 1
                    
        return cnt
