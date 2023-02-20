# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        flag = [False] * 301
        ans = ListNode(0)
        currNode = ans
        
        while head:
            if not flag[head.val]:
                currNode.next = ListNode(head.val)
                currNode = currNode.next
            flag[head.val] = True
            head = head.next
            
        return ans.next