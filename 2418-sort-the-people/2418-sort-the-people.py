class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        pack = dict(zip(heights, names))
        sortPack = sorted(pack.items(), key = lambda x : (-x[0], x[1]))
        return [x[1] for x in sortPack]