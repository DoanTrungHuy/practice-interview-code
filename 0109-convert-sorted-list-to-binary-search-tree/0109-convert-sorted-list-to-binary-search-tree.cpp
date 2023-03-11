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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    vector<int> v;
    
public:
    TreeNode *dfs(int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = dfs(left, mid - 1);
        root->right = dfs(mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return dfs(0, v.size() - 1);
    }
};