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
    int ans = 0;
    
public:
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }
        vector<int> left_node = dfs(root->left);
        vector<int> right_node = dfs(root->right);
        if (left_node.empty() or right_node.empty() 
            or root->val <= left_node[1] or root->val >= right_node[0]) {
            return {};
        }
        int sum = root->val + left_node[2] + right_node[2];
        ans = max(ans, sum);
        return {
            min({root->val, left_node[0]}),
            max({root->val, right_node[1]}),
            sum
        };
    }
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};