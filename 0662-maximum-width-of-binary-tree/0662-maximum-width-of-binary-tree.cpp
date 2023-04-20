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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        queue<pair<TreeNode *, unsigned long>> mq;
        mq.push({root, 1});
        unsigned long ans = 0;
        
        while (!mq.empty()) {
            int n = mq.size();

            ans = max(ans, mq.back().second - mq.front().second + 1);
            
            while (n--) {
                auto [node, val] = mq.front();
                mq.pop();
                
                if (node->left) {
                    mq.push({node->left, val * 2});
                }
                
                if (node->right) {
                    mq.push({node->right, val * 2 + 1});
                }
            }
        }
        
        return (int)ans;
    }
};