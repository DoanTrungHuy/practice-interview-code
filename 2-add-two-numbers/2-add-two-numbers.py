# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode(0)
        i, j, k = l1, l2, l3
        carry = 0
        
        while i or j or carry:
            num = carry
            
            if i:
                num += i.val
                i = i.next
            if j:
                num += j.val
                j = j.next
                
            carry = num // 10
            k.next = ListNode(num % 10)
            k = k.next
            
        return l3.next