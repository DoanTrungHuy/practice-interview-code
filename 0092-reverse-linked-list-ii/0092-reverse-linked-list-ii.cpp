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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *currNode = head;
        vector<int> v;
        
        while (currNode) {
            v.push_back(currNode->val);
            currNode = currNode->next;
        }
        
        reverse(v.begin() + left - 1, v.begin() + right);
        
        ListNode *answNode = new ListNode(0);
        currNode = answNode;
        
        for (int x : v) {
            currNode->next = new ListNode(x);
            currNode = currNode->next;
        }
        
        return answNode->next;
    }
};