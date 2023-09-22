class SegmentTree {
private:
    vector<int> tree;
    int n;
    
public:
    SegmentTree(int n) {
        tree.resize(4*n);
        this->n = n;
    }
    
    void update(int node, int left, int right, int index, int val) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = val;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, val);
        update(node*2 + 1, mid + 1, right, index, val);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get_max(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
            return 0;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_max(node*2, left, mid, q_left, q_right);
        int right_node = get_max(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        const int n = nums.size();
        const int MN = 1e5;
        SegmentTree st(2*MN);
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int num = nums[i] + MN;
            int prev_max = st.get_max(1, 0, 2*MN, max(0, num - k), num - 1);
            ans = max(ans, prev_max + 1);
            st.update(1, 0, 2*MN, num, prev_max + 1);
        }
        
        return ans;
    }
};