# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(0)
        i, j = head, ans
        s = 0
        
        while i:
            if i.val == 0:
                if s != 0:
                    j.next = ListNode(s)
                    j = j.next
                s = 0
            else:
                s += i.val
                    
            i = i.next
            
        return ans.next