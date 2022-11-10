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
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *cr = l3;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                cr->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cr = cr->next;
        }
        cr->next = l1 ? l1 : l2;
        return l3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = merge(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists.front();
    }
};