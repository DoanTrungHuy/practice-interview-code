# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        curr_node = head
        arr = []
        
        while curr_node:
            arr.append(curr_node.val)
            curr_node = curr_node.next
            
        i, j = 0, len(arr) - 1
        ans = ListNode(0)
        curr_node = ans
        
        while i <= j:
            if i == j:
                curr_node.next = ListNode(arr[i])
                curr_node = curr_node.next
                i += 1
                j -= 1 
            else:
                curr_node.next = ListNode(arr[i])
                curr_node = curr_node.next
                curr_node.next = ListNode(arr[j])
                curr_node = curr_node.next
                i += 1
                j -= 1
              
        curr_node = head
        temp_node = ans.next
        
        while curr_node:
            curr_node.val = temp_node.val
            curr_node = curr_node.next
            temp_node = temp_node.next