"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mapping = defaultdict(Node)
        currNode = head
        
        while currNode:
            mapping[currNode] = Node(currNode.val) 
            currNode = currNode.next
            
        currNode = head
        mapping[None] = None
        
        while currNode:
            mapping[currNode].next = mapping[currNode.next]
            mapping[currNode].random = mapping[currNode.random]
            currNode = currNode.next
            
        return mapping[head]