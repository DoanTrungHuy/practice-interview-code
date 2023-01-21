class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        k %= sum(chalk)
        
        for i, num in enumerate(chalk):
            k -= num
            if k < 0:
                return i
        return -1