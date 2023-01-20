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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *i = l1;
        ListNode *j = l2;
        ListNode *l3 = new ListNode(0);
        ListNode *k = l3;
        int carry = 0;
        int total = 0;
        while (i || j || carry) {
            total = carry;
            if (i) {
                total += i->val;
                i = i->next;
            }
            if (j) {
                total += j->val;
                j = j->next;
            }
            k->next = new ListNode(total % 10);
            carry = total / 10;
            k = k->next;
        }
        return l3->next;
    }
};