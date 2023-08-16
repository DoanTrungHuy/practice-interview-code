from sortedcontainers import SortedList

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        st = SortedList()
        l = 0
        n = len(nums)
        ans = []
        
        for r in range(n):
            st.add(nums[r])
            
            if r - l + 1 == k:
                ans.append(st[-1])
                st.remove(nums[l])
                l += 1
                
        return ans