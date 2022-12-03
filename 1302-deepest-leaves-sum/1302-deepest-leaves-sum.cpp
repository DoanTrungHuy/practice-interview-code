class Solution {
public:
   int maxDepth;
   map <int, int> m;
   void solve(TreeNode* node, int level = 0){
      if(!node)return;
      maxDepth = max(level, maxDepth);
      m[level] += node->val;
      solve(node->left, level + 1);
      solve(node->right, level + 1);
   }
   int deepestLeavesSum(TreeNode* root) {
      maxDepth = 0;
      m.clear();
      solve(root);
      return m[maxDepth];
   }
};