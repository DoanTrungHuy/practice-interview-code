class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        l1 = [1 for _ in range(numOnes)]
        l2 = [0 for _ in range(numZeros)]
        l3 = [-1 for _ in range(numNegOnes)]
        l = l1 + l2 + l3
        
        return sum(l[:k])