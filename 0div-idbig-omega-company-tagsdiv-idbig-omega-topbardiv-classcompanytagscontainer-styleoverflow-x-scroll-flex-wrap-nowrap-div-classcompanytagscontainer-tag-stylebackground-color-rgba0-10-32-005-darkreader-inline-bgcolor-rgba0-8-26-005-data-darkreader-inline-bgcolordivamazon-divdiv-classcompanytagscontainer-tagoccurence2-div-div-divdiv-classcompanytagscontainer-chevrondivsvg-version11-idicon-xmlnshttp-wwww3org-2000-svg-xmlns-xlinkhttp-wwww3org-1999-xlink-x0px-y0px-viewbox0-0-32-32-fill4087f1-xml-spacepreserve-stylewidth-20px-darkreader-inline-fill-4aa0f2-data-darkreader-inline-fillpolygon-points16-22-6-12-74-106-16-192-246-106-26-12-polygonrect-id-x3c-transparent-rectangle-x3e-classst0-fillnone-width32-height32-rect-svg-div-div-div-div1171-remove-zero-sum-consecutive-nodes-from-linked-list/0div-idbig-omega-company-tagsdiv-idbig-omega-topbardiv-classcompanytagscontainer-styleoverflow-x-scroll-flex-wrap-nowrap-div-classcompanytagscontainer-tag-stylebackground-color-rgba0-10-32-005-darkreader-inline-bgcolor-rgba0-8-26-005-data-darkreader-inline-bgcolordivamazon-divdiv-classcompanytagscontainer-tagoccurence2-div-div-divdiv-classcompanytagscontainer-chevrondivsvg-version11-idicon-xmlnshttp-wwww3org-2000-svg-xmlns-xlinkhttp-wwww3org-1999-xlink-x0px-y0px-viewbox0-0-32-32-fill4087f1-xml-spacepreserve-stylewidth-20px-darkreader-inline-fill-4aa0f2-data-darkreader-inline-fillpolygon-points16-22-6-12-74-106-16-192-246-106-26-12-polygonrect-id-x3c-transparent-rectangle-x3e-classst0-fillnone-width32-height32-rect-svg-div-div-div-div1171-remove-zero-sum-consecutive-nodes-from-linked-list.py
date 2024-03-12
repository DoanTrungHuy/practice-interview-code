# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # pref[right] = pref[left - 1]
        head = ListNode(0, head)
        hm = dict()
        
        curr = head
        pref = 0
        
        while curr:
            pref += curr.val
            hm[pref] = curr
            curr = curr.next
            
        curr = head
        answ = ListNode(0)
        temp = answ
        pref = 0
        
        while curr:
            pref += curr.val
            temp.next = hm[pref].next
            temp = temp.next
            curr = temp
            
        return answ.next