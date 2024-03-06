# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        
        turtle = head
        rabit = head
        
        while rabit != None and rabit.next != None:
            turtle = turtle.next
            rabit = rabit.next.next
            if turtle == rabit:
                return True
            
        return False