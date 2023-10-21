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
            if (tree[node] == INT_MIN) {
                tree[node] = 0;
            }
            tree[node] += value;
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
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n = nums.size();
        SegmentTree st(n);
        int max_sseq = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int max_ps = 0;
            max_ps = st.get_max(1, 0, n - 1, max(0, i - k), i);
            max_ps = max_ps == INT_MIN ? 0 : max_ps;
            st.update(1, 0, n - 1, i, max(max_ps + nums[i], nums[i]));
            max_sseq = max(max_sseq, max(max_ps + nums[i], nums[i]));
        }
        return max_sseq;
    }
};