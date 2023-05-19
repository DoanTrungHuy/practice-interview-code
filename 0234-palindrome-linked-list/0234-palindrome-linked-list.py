# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        currNode = head
        string = ""
        
        while currNode:
            string += str(currNode.val)
            currNode = currNode.next
            
        return string == string[::-1]