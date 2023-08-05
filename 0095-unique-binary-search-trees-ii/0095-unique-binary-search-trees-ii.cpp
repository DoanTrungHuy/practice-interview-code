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
    vector<TreeNode*> dfs(int s, int e) {
        if (s > e) {
            return {nullptr};
        }
        
        vector<TreeNode*> res;
        
        for (int i = s; i <= e; ++i) {
            vector<TreeNode*> left_node = dfs(s, i - 1);
            vector<TreeNode*> right_node = dfs(i + 1, e);
            
            for (auto a : left_node) {
                for (auto b : right_node) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};