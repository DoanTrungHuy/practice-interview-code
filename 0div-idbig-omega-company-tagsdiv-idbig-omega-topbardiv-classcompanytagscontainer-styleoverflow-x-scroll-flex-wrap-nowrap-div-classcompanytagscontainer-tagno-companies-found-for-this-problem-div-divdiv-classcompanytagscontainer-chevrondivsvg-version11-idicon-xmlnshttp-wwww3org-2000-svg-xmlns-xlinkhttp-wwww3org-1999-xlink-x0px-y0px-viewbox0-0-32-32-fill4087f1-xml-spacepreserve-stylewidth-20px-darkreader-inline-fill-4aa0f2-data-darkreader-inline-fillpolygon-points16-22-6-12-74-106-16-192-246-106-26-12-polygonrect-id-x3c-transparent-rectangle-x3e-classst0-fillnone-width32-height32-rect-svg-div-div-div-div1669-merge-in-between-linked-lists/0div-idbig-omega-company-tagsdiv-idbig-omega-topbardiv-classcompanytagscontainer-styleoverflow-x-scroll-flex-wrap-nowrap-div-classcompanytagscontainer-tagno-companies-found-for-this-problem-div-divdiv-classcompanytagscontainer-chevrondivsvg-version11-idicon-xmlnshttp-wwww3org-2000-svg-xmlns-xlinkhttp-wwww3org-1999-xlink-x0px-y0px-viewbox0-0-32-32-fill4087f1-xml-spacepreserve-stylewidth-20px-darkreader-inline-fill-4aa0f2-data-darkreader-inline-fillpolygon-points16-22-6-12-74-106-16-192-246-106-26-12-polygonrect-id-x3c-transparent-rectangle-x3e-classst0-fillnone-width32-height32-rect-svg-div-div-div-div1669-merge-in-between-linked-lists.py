# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        tail2 = list2
        
        while tail2.next:
            tail2 = tail2.next
            
        node_a = None
        node_b = None
        curr_node = list1
        prev_node = list1
        cnt = 0
        
        while curr_node:
            if cnt == a:
                node_a = prev_node
            if cnt == b:
                node_b = curr_node
            cnt += 1
            prev_node = curr_node
            curr_node = curr_node.next
        node_a.next = list2
        tail2.next = node_b.next if node_b else node_b
        del node_b
        
        return list1