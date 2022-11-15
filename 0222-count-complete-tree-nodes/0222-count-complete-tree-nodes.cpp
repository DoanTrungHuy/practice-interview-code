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
    int cnt;
    
public:
    void LNR(TreeNode *root) {
        if (!root) {
            return;
        }
        LNR(root->left);
        cnt++;
        LNR(root->right);
        
    }
    int countNodes(TreeNode* root) {
        cnt = 0;
        LNR(root);
        return cnt;
    }
};