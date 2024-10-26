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

class SegmentTree {
private:
    vector<int> tree;
    
public:
    SegmentTree(int n = 0) {
        tree.resize(4*n, INT_MIN);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) >> 1;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get_max(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or left > q_right) {
            return INT_MIN;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        int left_node = get_max(node*2, left, mid, q_left, q_right);
        int right_node = get_max(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
};

class Solution {
private:
    unordered_map<int, int> in, ou;
    vector<int> d;
    int index;
    
public:
    void dfs(TreeNode *root, int depth = 0) {
        in[root->val] = index++;
        d.push_back(depth);
        if (root->left) {
            dfs(root->left, depth + 1);
        }
        if (root->right) {
            dfs(root->right, depth + 1);
        }
        ou[root->val] = index++;
        d.push_back(depth);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        index = 0;
        dfs(root, 0);
        const int n = d.size();
        SegmentTree st(n);
        
        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, d[i]);
        }
        
        const int m = queries.size();
        
        vector<int> ans(m);
        
        for (int i = 0; i < m; ++i) {
            int l = in[queries[i]], r = ou[queries[i]];
            
            if (l - 1 >= 0) {
                ans[i] = max(ans[i], st.get_max(1, 0, n - 1, 0, l - 1));
            }
            
            if (r + 1 < n) {
                ans[i] = max(ans[i], st.get_max(1, 0, n - 1, r + 1, n - 1));
            }
        }
        
        return ans;
    }
};