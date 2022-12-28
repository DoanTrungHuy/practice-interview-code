class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = []

        for pile in piles:
            heappush(heap, -pile)

        while k:
            heappush(heap, -ceil(-heappop(heap) / 2))
            k -= 1

        return sum([-x for x in heap])