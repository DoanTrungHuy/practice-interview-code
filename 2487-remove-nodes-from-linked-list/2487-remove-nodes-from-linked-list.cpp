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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode *currNode = head;
        while (currNode) {
            v.push_back(currNode->val);
            currNode = currNode->next;
        }
        int n = v.size();
        int m = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            m = max(m, v[i]);
            if (v[i] < m) {
                v[i] = 0;
            }
        }
        head = new ListNode(0);
        currNode = head;
        for (int i = 0; i < n; ++i) {
            if (v[i] != 0) {
                currNode->next = new ListNode(v[i]);
                currNode = currNode->next;
            }
        }
        return head->next;
    }
};