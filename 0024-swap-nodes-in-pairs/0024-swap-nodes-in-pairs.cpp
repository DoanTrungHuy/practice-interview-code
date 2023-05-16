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
    ListNode* swapPairs(ListNode* head) {
        vector<int> v;
        ListNode *currNode = head;
        
        while (currNode) {
            v.push_back(currNode->val);
            currNode = currNode->next;
        }
        
        int n = (int)v.size();
        
        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n) {
                swap(v[i + 1], v[i]);
            }
        }
        
        ListNode *newNode = new ListNode(0);
        ListNode *tmpNode = newNode;
        
        for (int i = 0; i < n; ++i) {
            tmpNode->next = new ListNode(v[i]);
            tmpNode = tmpNode->next;
        } 
        
        return newNode->next;
    }
};