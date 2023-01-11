# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        n = len(lists)

        if n == 0:
            return None
        
        if n == 1:
            return lists[0]
        
        def merge(list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
            list3 = ListNode(0)
            currNode = list3
            
            while list1 and list2:
                if list1.val <= list2.val:
                    currNode.next = ListNode(list1.val)
                    list1 = list1.next
                else:
                    currNode.next = ListNode(list2.val)
                    list2 = list2.next
                currNode = currNode.next
                
            while list1:
                currNode.next = ListNode(list1.val)
                list1 = list1.next
                currNode = currNode.next
            
            while list2:
                currNode.next = ListNode(list2.val)
                list2 = list2.next
                currNode = currNode.next
                
            return list3.next
        
        while len(lists) > 1:
            lists.append(merge(lists[0], lists[1]))
            lists.remove(lists[0])
            lists.remove(lists[0])
            
        return lists[0]