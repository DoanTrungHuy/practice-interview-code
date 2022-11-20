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
    vector<int> v;
    
public:
    void LNR(TreeNode *root) {
        if (!root) {
            return;
        }
        LNR(root->left);
        v.push_back(root->val);
        LNR(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        LNR(root);
        int n = queries.size();
        vector<vector<int>> ans;
        int m = v.size();
        for (int i = 0; i < n; ++i) {
            int j = (lower_bound(v.begin(), v.end(), queries[i]) - v.begin());
            if (j < m and queries[i] == v[j]) {
                ans.push_back({v[j], v[j]});
            }
            else if (j == m) {
                ans.push_back({v[m - 1], -1});
            } 
            else if (j == 0) {
                ans.push_back({-1, v[j]});
            } 
            else {
                ans.push_back({v[j - 1], v[j]});
            }
        }
        return ans;
    }
};