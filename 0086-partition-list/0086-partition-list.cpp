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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        
        ListNode *tLeft = left, *tRight = right;
        
        while (head) {
            if (head->val < x) {
                tLeft->next = head;
                tLeft = tLeft->next;
            }
            else {
                tRight->next = head;
                tRight = tRight->next;
            }
            head = head->next;
        }
        
        tLeft->next = right->next;
        tRight->next = nullptr;
        
        return left->next;
    }
};