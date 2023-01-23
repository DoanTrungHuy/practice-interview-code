class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        
        n = len(position)
        
        def trimPos(target: int) -> int:
            cnt = 1
            cur = position[0]
            
            for i in range(1, n):
                if position[i] - cur >= target:
                    cnt += 1
                    cur = position[i]
            
            return cnt
        
        ans = inf
        left, right = 1, position[-1] - position[0]
        ans = -1
        
        while left <= right:
            mid = (left + right) // 2
            if trimPos(mid) < m:
                right = mid - 1
            else:
                ans = max(ans, mid)
                left = mid + 1
                
        return ans