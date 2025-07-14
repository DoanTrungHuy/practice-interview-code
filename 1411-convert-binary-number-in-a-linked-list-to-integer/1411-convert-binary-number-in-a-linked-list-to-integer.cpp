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
    int getDecimalValue(ListNode* head) {
        ListNode *currNode = head;
        int ans = 0, i = 0, sz = 0;

        while (currNode) {
            sz++;
            currNode = currNode->next;
        }

        currNode = head;

        while (currNode) {
            ans += currNode->val * (1 << (sz - i - 1));
            i++;
            currNode = currNode->next;
        }

        return ans;
    }
};