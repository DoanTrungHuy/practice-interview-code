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
    int res = 0;
    
public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 1;
        }
        int node_left = dfs(root->left);
        int node_right = dfs(root->right);
        if (node_left == 0 or node_right == 0) {
            res++;
            return 2;
        }
        if (node_left == 2 or node_right == 2) {
            return 1;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            res++;
        }
        return res;
    }
};