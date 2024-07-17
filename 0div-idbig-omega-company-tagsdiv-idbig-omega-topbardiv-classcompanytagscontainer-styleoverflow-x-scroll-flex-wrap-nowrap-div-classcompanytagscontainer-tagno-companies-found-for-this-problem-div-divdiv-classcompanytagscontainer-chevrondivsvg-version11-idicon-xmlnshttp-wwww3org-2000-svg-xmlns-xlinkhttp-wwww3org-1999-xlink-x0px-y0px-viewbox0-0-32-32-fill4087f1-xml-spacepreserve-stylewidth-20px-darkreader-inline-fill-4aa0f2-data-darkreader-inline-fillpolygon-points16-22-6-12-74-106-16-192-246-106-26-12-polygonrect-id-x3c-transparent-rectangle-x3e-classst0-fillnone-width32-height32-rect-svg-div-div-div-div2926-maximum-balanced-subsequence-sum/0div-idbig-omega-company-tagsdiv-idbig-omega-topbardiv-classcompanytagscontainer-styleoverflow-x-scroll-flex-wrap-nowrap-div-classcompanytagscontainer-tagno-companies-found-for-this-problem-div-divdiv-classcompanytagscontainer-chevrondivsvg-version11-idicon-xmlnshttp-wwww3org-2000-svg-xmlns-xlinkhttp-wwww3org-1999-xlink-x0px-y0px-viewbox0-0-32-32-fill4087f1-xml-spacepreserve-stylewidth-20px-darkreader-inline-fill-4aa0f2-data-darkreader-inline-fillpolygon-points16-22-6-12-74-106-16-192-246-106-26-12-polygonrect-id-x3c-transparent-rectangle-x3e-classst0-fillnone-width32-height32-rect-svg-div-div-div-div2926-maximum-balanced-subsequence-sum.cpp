template <class T>
struct SegmentTree {
    vector<T> tree;
    
    SegmentTree() {
        
    }
    
    SegmentTree(int n) {
        tree.resize(4*(n + 1));
    }
    
    void update(int node, int left, int right, int index, T value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = max(tree[node], value);
            return;
        }
        int mid = (left + right) >> 1;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    T get_max(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        T left_node = get_max(node*2, left, mid, q_left, q_right);
        T right_node = get_max(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        // nums[i] - nums[j] >= i - j 

        // nums[i] - i >= nums[j] - j  -----  CON
        // j < i
        // nums[i] + max(CON) -> prev sum max (1, compress[nums[i] - i])
        
        const int n = nums.size();
        map<int, int> compress;
        
        for (int i = 0; i < n; ++i) {
            compress[nums[i] - i] = 0;
        }
        
        int times = 0;
        
        for (auto &[v, f] : compress) {
            compress[v] = ++times;
        }
        
        SegmentTree<long long> st(n);
        
        long long res = LLONG_MIN;
        
        for (int i = 0; i < n; ++i) {
            int prior_loc = compress[nums[i] - i];
            long long new_sum = 1LL*nums[i] + st.get_max(1, 1, times, 1, prior_loc);
            res = max(res, new_sum);
            st.update(1, 1, times, prior_loc, new_sum);
        }
        
        return res;
    }
};