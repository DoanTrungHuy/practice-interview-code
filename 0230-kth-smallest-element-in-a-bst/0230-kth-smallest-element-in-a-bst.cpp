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
    int k;
    int ans;
    
public:

    void solve(TreeNode *node) {
        if(!node) return;
        solve(node->left);
        k--;
        if (k == 0) {
            ans = node->val;
        }
        solve(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        solve(root);
        return ans;
    }
};