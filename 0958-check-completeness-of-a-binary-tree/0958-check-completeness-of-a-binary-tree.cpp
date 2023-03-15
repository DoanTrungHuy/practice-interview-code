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
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> mq;
        mq.push(root);
        bool flag = true;
        while (!mq.empty()) {
            TreeNode *curr = mq.front();
            mq.pop();
            if (curr == nullptr) {
                flag = false;
            }
            else {
                if (!flag) {
                    return false;
                }
                mq.push(curr->left);
                mq.push(curr->right);
            }
        }
        return true;
    }
};