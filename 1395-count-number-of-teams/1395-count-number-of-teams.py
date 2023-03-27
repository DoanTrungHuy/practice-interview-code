class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        
        for j in range(1, n - 1):
            leftGreater = 0
            leftSmaller = 0
            
            for i in range(0, j):
                if rating[i] < rating[j]:
                    leftSmaller += 1
                elif rating[i] > rating[j]:
                    leftGreater += 1
            
            rightGreater = 0
            rightSmaller = 0
            
            for k in range(j + 1, n):
                if rating[k] < rating[j]:
                    rightSmaller += 1
                elif rating[k] > rating[j]:
                    rightGreater += 1
                    
            ans += leftGreater * rightSmaller + leftSmaller * rightGreater
            
        return ans