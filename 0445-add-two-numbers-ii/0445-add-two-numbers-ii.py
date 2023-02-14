# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        currNode = head
        nextNode = head.next
        prevNode = None
        
        while currNode and nextNode:
            currNode.next = prevNode
            prevNode = currNode
            currNode = nextNode
            nextNode = nextNode.next
            
        currNode.next = prevNode
        prevNode = currNode
            
        return prevNode
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.reverseList(l1)
        l2 = self.reverseList(l2)
        
        l3 = ListNode(0)
        cr = l3
        carry = 0
        
        while l1 or l2 or carry:
            total = carry
            if l1:
                total += l1.val
                l1 = l1.next
            if l2:
                total += l2.val
                l2 = l2.next
            cr.next = ListNode(total % 10)
            cr = cr.next
            carry = total // 10
            
        return self.reverseList(l3.next)
        