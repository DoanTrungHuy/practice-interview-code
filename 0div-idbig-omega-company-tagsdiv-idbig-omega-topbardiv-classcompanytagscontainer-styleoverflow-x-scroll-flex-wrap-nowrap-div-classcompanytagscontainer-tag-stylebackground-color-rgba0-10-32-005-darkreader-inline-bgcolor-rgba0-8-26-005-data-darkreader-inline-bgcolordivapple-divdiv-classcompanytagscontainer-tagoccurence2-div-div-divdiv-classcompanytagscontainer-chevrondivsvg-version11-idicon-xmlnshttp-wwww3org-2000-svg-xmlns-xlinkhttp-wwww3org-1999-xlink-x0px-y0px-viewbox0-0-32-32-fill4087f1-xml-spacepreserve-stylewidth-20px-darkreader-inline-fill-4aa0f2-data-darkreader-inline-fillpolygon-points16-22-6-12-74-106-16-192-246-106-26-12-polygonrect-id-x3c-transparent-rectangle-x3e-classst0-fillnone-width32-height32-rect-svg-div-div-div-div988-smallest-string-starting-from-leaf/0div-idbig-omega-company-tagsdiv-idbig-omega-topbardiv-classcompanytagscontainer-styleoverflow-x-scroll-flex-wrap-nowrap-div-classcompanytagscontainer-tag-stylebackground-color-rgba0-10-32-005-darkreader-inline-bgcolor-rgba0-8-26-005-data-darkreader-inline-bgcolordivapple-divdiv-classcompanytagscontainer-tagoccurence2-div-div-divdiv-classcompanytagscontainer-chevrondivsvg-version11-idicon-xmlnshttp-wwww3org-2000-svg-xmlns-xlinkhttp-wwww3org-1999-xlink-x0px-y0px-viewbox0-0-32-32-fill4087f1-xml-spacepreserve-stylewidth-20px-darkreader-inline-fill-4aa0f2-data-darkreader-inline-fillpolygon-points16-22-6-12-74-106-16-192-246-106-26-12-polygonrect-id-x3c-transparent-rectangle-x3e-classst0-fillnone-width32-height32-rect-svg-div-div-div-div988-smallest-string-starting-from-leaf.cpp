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
    void dfs(TreeNode* root, string tmp, string &ans) {
        if (!root) {
            return;
        }
        if (!root->left and !root->right) {
            tmp.push_back(root->val + 'a');
            reverse(tmp.begin(), tmp.end());
            ans = min(ans, tmp);
            return;
        }
        dfs(root->left, tmp + char(root->val + 'a'), ans);
        dfs(root->right, tmp + char(root->val + 'a'), ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        ans += char(255);
        dfs(root, "", ans);
        return ans;
    }
};