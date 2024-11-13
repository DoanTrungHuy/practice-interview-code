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
            tree[node] += value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
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
        return left_node + right_node;
    }
};

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();
        map<int, int> compress;
        
        for (int i = 0; i < n; ++i) {
            compress[nums[i]];
            compress[lower - nums[i]];
            compress[upper - nums[i]];
        }
        
        int times = 1;
        
        for (auto &[k, v] : compress) {
            v = times++;
        }
        
        SegmentTree st(times + 1);
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans -= st.get(1, 0, times, 0, compress[lower - nums[i]] - 1);
            ans += st.get(1, 0, times, 0, compress[upper - nums[i]]);
            st.update(1, 0, times, compress[nums[i]], 1);
        }
        
        return ans;
    }
};