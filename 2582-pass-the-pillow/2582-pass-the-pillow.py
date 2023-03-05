class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cnt = 1
        step = 1

        for i in range(time):
            if cnt == n:
                step = -1
            if cnt == 1:
                step = 1
            cnt += step
            
        return cnt