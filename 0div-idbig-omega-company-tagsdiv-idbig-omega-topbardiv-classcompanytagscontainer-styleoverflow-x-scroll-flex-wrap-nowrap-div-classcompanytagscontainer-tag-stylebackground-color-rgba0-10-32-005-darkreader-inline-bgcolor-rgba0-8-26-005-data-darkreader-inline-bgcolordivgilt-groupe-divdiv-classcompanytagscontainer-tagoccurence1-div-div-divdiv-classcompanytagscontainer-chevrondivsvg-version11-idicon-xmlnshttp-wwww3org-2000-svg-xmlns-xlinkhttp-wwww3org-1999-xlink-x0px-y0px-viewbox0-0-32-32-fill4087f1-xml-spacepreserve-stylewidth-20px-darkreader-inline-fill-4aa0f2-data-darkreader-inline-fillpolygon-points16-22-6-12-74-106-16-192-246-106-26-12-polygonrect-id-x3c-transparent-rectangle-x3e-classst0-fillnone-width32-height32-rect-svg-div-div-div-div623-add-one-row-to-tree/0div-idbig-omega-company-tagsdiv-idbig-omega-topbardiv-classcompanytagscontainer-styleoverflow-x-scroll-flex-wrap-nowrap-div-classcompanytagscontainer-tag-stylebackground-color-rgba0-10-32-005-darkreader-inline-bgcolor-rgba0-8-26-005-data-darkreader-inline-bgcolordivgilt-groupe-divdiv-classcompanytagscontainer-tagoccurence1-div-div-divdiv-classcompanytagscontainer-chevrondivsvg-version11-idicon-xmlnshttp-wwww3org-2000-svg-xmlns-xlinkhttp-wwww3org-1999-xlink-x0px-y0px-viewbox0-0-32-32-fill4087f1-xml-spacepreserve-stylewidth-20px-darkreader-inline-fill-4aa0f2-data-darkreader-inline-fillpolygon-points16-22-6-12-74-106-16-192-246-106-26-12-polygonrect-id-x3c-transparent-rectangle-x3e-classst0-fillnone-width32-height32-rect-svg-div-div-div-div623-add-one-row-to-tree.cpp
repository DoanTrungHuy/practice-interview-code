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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        
        queue<TreeNode*> mq;
        mq.push(root);
        int cnt_depth = 0;
        
        while (!mq.empty()) {
            cnt_depth++;
            if (cnt_depth == depth - 1) {
                break;
            }
            int n = mq.size();
            while (n--) {
                TreeNode* node = mq.front();
                mq.pop();
                if (node->left) {
                    mq.push(node->left);
                }
                if (node->right) {
                    mq.push(node->right);
                } 
            }
        }
        
        while (mq.size()) {
            TreeNode* node = mq.front();
            mq.pop();
            TreeNode* tmp_left_node = node->left;
            TreeNode* tmp_right_node = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = tmp_left_node;
            node->right->right = tmp_right_node;
        }
        
        return root;
    }
};