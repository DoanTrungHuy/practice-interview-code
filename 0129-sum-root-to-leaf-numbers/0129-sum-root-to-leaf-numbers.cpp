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
public:
    int dfs(TreeNode *root, string num) {
        if (!root) {
            return 0;
        }
        if (!root->left and !root->right) {
            return stoi(num + char(root->val + '0'));
        }
        int cnt = 0;
        cnt += dfs(root->left, num + char(root->val + '0'));
        cnt += dfs(root->right, num + char(root->val + '0'));
        return cnt;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, "");
    }
};