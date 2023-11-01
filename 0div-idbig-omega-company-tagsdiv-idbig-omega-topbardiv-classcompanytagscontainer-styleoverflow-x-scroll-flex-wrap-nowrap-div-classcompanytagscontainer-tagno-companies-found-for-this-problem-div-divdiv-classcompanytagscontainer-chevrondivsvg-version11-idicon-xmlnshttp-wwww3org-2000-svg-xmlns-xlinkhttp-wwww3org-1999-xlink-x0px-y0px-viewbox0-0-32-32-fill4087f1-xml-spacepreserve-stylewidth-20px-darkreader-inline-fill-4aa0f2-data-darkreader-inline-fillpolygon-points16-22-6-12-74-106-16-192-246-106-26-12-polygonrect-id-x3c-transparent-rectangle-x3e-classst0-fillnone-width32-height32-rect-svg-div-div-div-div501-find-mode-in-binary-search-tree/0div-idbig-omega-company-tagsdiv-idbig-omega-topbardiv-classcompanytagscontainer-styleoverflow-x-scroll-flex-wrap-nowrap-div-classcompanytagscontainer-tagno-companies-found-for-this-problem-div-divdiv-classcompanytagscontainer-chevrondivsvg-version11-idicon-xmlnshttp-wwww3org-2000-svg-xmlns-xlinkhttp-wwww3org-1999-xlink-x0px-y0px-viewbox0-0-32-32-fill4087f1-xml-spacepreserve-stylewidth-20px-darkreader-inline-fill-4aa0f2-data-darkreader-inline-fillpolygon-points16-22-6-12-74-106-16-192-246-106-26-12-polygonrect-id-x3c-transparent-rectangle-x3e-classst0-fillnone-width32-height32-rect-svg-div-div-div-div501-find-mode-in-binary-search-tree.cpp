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
    unordered_map<int, int> um;
    
public:
    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        um[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        int max_f = 0;
        for (const auto [v, c] : um) {
            max_f = max(max_f, c);
        }
        for (const auto [v, c] : um) {
            if (c == max_f) {
                ans.push_back(v);
            }
        }
        return ans;
    }
};