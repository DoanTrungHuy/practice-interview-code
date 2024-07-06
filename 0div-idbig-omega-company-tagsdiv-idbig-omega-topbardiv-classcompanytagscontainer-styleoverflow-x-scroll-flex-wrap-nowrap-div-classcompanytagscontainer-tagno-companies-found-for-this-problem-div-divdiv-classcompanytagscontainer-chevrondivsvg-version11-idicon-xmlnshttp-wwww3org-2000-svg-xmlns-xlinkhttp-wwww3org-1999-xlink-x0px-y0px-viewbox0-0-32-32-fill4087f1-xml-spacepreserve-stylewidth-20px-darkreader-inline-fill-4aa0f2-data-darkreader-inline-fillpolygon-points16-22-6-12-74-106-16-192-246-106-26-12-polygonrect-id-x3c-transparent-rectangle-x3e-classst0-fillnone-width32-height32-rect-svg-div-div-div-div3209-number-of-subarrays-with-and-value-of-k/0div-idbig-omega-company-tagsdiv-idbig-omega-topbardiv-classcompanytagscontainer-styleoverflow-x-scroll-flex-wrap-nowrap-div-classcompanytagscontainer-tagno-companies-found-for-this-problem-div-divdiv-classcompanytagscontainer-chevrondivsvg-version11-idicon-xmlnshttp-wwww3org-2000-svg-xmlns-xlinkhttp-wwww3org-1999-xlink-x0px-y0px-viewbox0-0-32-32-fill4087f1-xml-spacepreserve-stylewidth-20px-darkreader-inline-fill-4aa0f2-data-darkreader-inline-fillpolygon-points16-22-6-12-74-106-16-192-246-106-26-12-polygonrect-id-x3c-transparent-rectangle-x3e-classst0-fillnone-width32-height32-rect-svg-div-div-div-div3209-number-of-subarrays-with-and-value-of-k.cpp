class SegmentTree {
private:
    vector<int> tree;
    
public:
    SegmentTree(int n = 0) {
        tree.resize(4*n);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] & tree[node*2 + 1];
    }
    
    int get_and(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return INT_MAX;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_and(node*2, left, mid, q_left, q_right);
        int right_node = get_and(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node & right_node;
    }
};

class Solution {
private:
    int n;
    SegmentTree st;
    
public:
    long long atLeast(int k) {
        long long ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j <= i && st.get_and(1, 0, n - 1, j, i) < k) {
                ++j;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        n = nums.size();
        st = SegmentTree(n);
        
        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, nums[i]);
        }
        
        return atLeast(k) - atLeast(k + 1);
    }
};