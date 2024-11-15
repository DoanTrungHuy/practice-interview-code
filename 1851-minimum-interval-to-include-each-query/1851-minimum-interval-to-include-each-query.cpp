class SegmentTree {
public:
    vector<int> tree, lazy;
    
    SegmentTree(int n = 0) {
        tree.resize(4*n, INT_MAX);
        lazy.resize(4*n, INT_MAX);
    }
    
    void down(int node, int left, int right) {
        if (left > right || lazy[node] == 0) {
            return;
        }
        tree[node] = min(tree[node], lazy[node]);
        if (left != right) {
            lazy[node*2] = min(lazy[node*2], lazy[node]);
            lazy[node*2 + 1] = min(lazy[node*2 + 1], lazy[node]);
        }
    }
    
    void update(int node, int left, int right, int q_left, int q_right, int value) {
        down(node, left, right);
        if (q_left > right or left > q_right) {
            return;
        }
        if (q_left <= left and right <= q_right) {
            lazy[node] = min(lazy[node], value);
            down(node, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, q_left, q_right, value);
        update(node*2 + 1, mid + 1, right, q_left, q_right, value);
        tree[node] = min(tree[node*2], tree[node*2 + 1]);
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        down(node, left, right);
        if (q_left > right or left > q_right) {
            return INT_MAX;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return min(left_node, right_node);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int, int> cp;
        
        for (vector<int> iter : intervals) {
            int l = iter[0];
            int r = iter[1];
            cp[l], cp[r];
        }
        
        for (int q : queries) {
            cp[q];
        }
        
        int times = 0;
        
        for (auto &[k, v] : cp) {
            v = times++;
        }
        
        SegmentTree st(times);
        
        for (vector<int> iter : intervals) {
            int l = iter[0];
            int r = iter[1];
            st.update(1, 0, times, cp[l], cp[r], r - l + 1);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = st.get(1, 0, times, cp[q], cp[q]);
            ans.push_back(val == INT_MAX ? -1 : val);
        }
        
        return ans;
    }
};