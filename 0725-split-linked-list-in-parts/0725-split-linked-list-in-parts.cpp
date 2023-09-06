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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        
        ListNode *currNode = head;
        int size_list = 0;
        
        while (currNode) {
            size_list++;
            currNode = currNode->next;
        }
        
        int size_split = size_list / k, element_remain = size_list % k;
        currNode = head;
        ListNode *prevNode = head;
        
        for (int i = 0; i < k; ++i) {
            ans.push_back(currNode);
            
            for (int j = 0; j < size_split + (i < element_remain); ++j) {
                prevNode = currNode;
                currNode = currNode->next;
            }
            
            if (prevNode) {
                prevNode->next = nullptr;
            }
        }
        
        return ans;
    }
};