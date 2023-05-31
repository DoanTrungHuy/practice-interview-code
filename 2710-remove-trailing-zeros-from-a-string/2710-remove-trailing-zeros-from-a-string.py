class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        n = len(num)
        for i in range(n - 1, -1, -1):
            if num[i] != '0':
                return num[:i + 1]
        return num