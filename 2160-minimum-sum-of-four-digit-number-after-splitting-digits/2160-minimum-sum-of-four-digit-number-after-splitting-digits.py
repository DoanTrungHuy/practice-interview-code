class Solution:
    def minimumSum(self, num: int) -> int:
        num = list(str(num))
        num.sort()
        return int(num[0] + num[2]) + int(num[1] + num[3])