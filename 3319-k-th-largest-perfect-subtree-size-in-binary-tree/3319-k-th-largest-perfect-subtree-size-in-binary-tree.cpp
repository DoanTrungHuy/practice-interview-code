class Solution {
public:
    using pii = pair<bool, int>;
    vector<int> ans;

    pii dfs(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }
        
        auto [ok_r, rz] = dfs(root->right);
        auto [ok_l, lz] = dfs(root->left);
        
        if (lz == rz && ok_l && ok_r) {
            ans.push_back(lz + rz + 1);
            return {true, lz + rz + 1};
        }
        
        return {false, 0};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(ans.rbegin(), ans.rend());
        
        if (ans.size() < k) {
            return -1;
        }
        
        return ans[k - 1];
    }
};
