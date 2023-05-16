/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> um;
        ListNode *currNode = head;
        
        while (currNode) {
            um[currNode->val]++;
            currNode = currNode->next;
        }
        
        ListNode *newNode = new ListNode(0);
        ListNode *tmpNode = newNode;
        
        for (auto [key, val] : um) {
            if (val > 1) {
                continue;
            }
            tmpNode->next = new ListNode(key);
            tmpNode = tmpNode->next;
        }
        
        return newNode->next;
    }
};