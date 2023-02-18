# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        list3 = ListNode(0)
        i, j, k = list1, list2, list3
        
        while i and j:
            if i.val < j.val:
                k.next = ListNode(i.val)
                i = i.next
            else:
                k.next = ListNode(j.val)
                j = j.next
            k = k.next
            
        k.next = i if i else j
        
        return list3.next