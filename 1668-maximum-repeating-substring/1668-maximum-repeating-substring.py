class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        check = word
        cnt = 0
        while check in sequence:
            cnt += 1
            check += word
        return cnt