class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        nums = list(range(1, n + 1))
        return sorted(nums, key = lambda num: str(num))