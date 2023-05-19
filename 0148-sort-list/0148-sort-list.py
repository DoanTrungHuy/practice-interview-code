# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        currNode = head
        listNode = []
        
        while currNode:
            listNode.append(currNode.val)
            currNode = currNode.next
            
        listNode.sort()
        
        answNode = ListNode(0)
        dummNode = answNode
        
        for nodeVal in listNode:
            dummNode.next = ListNode(nodeVal)
            dummNode = dummNode.next
        
        return answNode.next