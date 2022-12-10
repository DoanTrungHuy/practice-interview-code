class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        maxLen = 0
        for s in strs:
            if s.isnumeric():
                maxLen = max(maxLen, int(s))
            else:
                maxLen = max(maxLen, len(s))
        return maxLen