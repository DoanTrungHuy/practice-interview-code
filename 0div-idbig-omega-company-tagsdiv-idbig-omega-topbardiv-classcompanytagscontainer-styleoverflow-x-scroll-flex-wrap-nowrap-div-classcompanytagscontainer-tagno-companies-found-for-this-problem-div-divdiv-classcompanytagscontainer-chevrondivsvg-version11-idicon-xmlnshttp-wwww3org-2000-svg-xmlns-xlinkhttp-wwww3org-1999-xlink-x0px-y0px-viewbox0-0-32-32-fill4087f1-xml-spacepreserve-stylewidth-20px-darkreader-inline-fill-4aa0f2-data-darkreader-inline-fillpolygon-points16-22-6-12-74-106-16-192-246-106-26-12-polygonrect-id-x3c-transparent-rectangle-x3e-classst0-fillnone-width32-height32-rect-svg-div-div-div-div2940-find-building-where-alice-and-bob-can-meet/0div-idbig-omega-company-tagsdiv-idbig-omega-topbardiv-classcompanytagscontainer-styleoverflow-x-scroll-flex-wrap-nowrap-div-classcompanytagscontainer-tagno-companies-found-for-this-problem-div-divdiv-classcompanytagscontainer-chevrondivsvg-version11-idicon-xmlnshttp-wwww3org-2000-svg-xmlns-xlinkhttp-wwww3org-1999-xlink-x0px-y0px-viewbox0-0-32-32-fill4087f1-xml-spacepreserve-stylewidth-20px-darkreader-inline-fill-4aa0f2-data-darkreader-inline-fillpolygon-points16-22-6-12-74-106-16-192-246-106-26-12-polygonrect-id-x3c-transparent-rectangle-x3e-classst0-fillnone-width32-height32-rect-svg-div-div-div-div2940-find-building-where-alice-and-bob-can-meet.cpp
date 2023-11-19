class SegmentTree {
public:
    vector<int> tree;
    
    SegmentTree(int n = 0) {
        tree.resize(4*n);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (left > index or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or left > q_right) {
            return 0;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int n = heights.size();
        SegmentTree st(n);
        
        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, heights[i]);
        }
        
        const int m = queries.size();
        
        vector<int> ans(m, -1);
        
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0];
            int b = queries[i][1];
            
            if (a > b) {
                swap(a, b);
            }
            
            if (a == b) {
                ans[i] = a;
            }
            else if (heights[a] < heights[b]) {
                ans[i] = b;
            }
            else {
                int left = b + 1;
                int right = n - 1;
                int leftmost_index = -1;

                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (st.get(1, 0, n - 1, b + 1, mid) > max(heights[a], heights[b])) {
                        leftmost_index = mid;
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }

                ans[i] = leftmost_index;
            }
        }
        
        return ans;
    }
};