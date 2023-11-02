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
    unordered_map<TreeNode*, int> memo, cnt;
    int ans = 0;
    
public:
    void dp(TreeNode* root) {
        if (!root) {
            return;
        }
        dp(root->left);
        dp(root->right);
        memo[root] = root->val;
        cnt[root] = 1;
        if (root->left) {
            memo[root] += memo[root->left];
            cnt[root] += cnt[root->left];
        }
        if (root->right) {
            memo[root] += memo[root->right];
            cnt[root] += cnt[root->right];
        }
    }
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        if (memo[root] / cnt[root] == root->val) {
            ans++;
        }
        dfs(root->left);
        dfs(root->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        dp(root);
        dfs(root);
        return ans;
    }
};