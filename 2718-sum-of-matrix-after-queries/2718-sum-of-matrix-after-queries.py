class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
            remainRow, remainCol = n, n
            m = len(queries)
            checkRow, checkCol = set(), set()
            total = 0
            
            for i in range(m - 1, -1, -1):
                typei, indexi, vali = queries[i]
                
                if typei == 0 and indexi not in checkRow:
                    checkRow.add(indexi)
                    total += vali*remainCol
                    remainRow -= 1
                    
                if typei == 1 and indexi not in checkCol:
                    checkCol.add(indexi)
                    total += vali*remainRow
                    remainCol -= 1
                    
            return total