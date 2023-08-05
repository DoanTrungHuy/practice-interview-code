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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> v;
        
        ListNode *curr = head;
        
        while (curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        vector<int> g;
        
        for (int i = 0; i < v.size() - 1; ++i) {
            g.push_back(__gcd(v[i], v[i + 1]));
        }
        
        ListNode *answ = new ListNode(0);
        curr = answ;
        int i = 0, j = 0;
        
        while (i < v.size() or j < g.size()) {
            if (i < v.size()) {
                curr->next = new ListNode(v[i]);
                curr = curr->next;
                i++;
            }
            
            if (j < g.size()) {
                curr->next = new ListNode(g[j]);
                curr = curr->next;
                j++;
            }
        }
        
        return answ->next;
    }
};