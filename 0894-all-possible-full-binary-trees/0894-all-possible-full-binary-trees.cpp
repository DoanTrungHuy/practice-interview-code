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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> res;
        
        for (int i = 2; i < n; i += 2) {
            vector<TreeNode*> all_way_node_left = allPossibleFBT(i - 1);
            vector<TreeNode*> all_way_node_right = allPossibleFBT(n - i);
            
            for (TreeNode* node_left : all_way_node_left) {
                for (TreeNode* node_right : all_way_node_right) {
                    TreeNode *root = new TreeNode(0, node_left, node_right);
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};