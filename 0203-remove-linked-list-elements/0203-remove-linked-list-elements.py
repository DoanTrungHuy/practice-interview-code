# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        head1 = ListNode(0)
        list1 = head1
        currNode = head
        
        while currNode:
            if currNode.val != val:
                list1.next = ListNode(currNode.val)
                list1 = list1.next
            currNode = currNode.next
            
        return head1.next