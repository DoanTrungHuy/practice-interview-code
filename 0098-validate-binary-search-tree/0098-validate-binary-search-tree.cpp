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
    vector<int> sav;
public:
    void LNR(TreeNode *root) {
        if (!root) {
            return;
        }
        LNR(root->left);
        sav.push_back(root->val);
        LNR(root->right);
    }
    bool isValidBST(TreeNode* root) {
        LNR(root);
        for (int i = 1; i < (int)sav.size(); ++i) {
            if (sav[i - 1] >= sav[i]) {
                return false;
            }
        }
        return true;
    }
};