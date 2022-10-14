# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Case 1: [1,3,4,7,1,2,6]
        #              ^     ^
        # fastNode == nullptr
        
        # Case 2: [1,2,3,4]
        #            ^   ^
        # fastNode.next == nullptr
        
        slowNode = head
        fastNode = head.next
        
        if not fastNode:
            return None
        
        if not fastNode.next:
            slowNode.next = None
            return slowNode
        
        while fastNode.next and fastNode.next.next:
            slowNode = slowNode.next
            fastNode = fastNode.next.next
        
        nextNode = slowNode.next
        nextNode = None
        
        slowNode.next = slowNode.next.next
        
        return head