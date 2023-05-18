# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        currNode = head
        listNode = []
        
        while currNode:
            listNode.append(currNode.val)
            currNode = currNode.next
            
        n = len(listNode)
        
        for i in range(0, n + 1, k):
            listNode[i - k:i] = listNode[i - k:i][::-1]
        
        answNode = ListNode(0)
        dummNode = answNode
        
        for i in range(n):
            dummNode.next = ListNode(listNode[i])
            dummNode = dummNode.next
            
        return answNode.next