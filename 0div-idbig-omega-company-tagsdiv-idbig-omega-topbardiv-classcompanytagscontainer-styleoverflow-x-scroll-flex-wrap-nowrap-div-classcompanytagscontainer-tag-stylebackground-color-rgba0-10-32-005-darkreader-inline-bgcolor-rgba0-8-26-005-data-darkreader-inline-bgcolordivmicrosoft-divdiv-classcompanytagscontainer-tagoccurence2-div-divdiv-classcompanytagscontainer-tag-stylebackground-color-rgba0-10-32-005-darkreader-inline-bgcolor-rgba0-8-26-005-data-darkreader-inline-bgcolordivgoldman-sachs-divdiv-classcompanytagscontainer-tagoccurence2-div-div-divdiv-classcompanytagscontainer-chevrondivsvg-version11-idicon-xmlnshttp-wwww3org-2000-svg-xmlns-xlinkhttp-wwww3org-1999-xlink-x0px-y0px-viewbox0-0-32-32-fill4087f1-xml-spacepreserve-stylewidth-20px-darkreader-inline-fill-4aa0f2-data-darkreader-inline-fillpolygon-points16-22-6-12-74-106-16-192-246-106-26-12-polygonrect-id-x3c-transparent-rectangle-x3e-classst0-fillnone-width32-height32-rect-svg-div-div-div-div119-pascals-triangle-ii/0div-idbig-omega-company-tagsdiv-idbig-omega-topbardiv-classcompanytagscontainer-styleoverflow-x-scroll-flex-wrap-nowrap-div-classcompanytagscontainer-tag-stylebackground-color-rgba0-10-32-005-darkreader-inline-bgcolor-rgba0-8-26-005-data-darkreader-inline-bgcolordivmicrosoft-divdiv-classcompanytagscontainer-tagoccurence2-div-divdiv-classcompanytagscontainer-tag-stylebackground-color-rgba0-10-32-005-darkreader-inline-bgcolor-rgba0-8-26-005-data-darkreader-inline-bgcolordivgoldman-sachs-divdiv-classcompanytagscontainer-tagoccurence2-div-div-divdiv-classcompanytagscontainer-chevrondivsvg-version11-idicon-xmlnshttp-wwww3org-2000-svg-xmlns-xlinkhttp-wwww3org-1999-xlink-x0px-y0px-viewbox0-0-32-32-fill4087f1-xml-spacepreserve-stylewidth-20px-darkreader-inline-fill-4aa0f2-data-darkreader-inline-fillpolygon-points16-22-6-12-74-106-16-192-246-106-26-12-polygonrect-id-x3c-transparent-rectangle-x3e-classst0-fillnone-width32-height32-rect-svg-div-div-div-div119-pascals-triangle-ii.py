class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = []
        for i in range(rowIndex + 1):
            tmp = [1] * (i + 1)
            for j in range(1, i):
                tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j]
            ans.append(tmp)
        return ans[rowIndex]