# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 1->2->3->4->5
        # ^  ^  ^
        # 1<-2<-3<-4->5
        #          ^  ^  ^
        
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