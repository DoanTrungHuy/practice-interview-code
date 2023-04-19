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
    int maxStep;
    
public:
    void dfs(TreeNode *root, bool flip, int step) {
        if (!root) {
            return;
        }
        maxStep = max(maxStep, step);
        if (flip) {
            dfs(root->right, !flip, step + 1);
            dfs(root->left, flip, 1);
        }
        else {
            dfs(root->left, !flip, step + 1);
            dfs(root->right, flip, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        maxStep = 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return maxStep;
    }
};