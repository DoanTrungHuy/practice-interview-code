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
    vector<int> inorder, postorder;
    int curr;
    
public:
    TreeNode* build(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int i = 0;
        while (curr >= 0 and inorder[i] != postorder[curr]) {
            i++;
        }
        curr--;
        TreeNode *root = new TreeNode(inorder[i]);
        root->right = build(i + 1, r);
        root->left = build(l, i - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        this->curr = inorder.size() - 1;
        return build(0, curr);
    }
};