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
    int s = 0;
    int maxDepth = 1;
    void dfs(TreeNode *root, int depth) {
        if (!root) {
            return;
        }
        if (maxDepth <= depth) {
            if (maxDepth < depth) {
                s = root->val;
                maxDepth = depth;
            } 
            else if (maxDepth == depth) {
                s += root->val;
            }
        }
        dfs(root->left, depth + 1), dfs(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 1);
        return s;
    }
};