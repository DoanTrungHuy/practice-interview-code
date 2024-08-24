struct SegmentTree {
    vector<long long> tree, lazy;
    
    SegmentTree() {}
    
    SegmentTree(int n) {
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    
    void down(int node, int left, int right) {
        if (left > right or lazy[node] == 0) {
            return;
        }
        tree[node] += lazy[node]*(right - left + 1);
        if (left != right) {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    void update(int node, int left, int right, int q_left, int q_right, int value) {
        down(node, left, right);
        if (left > q_right or q_left > right) {
            return;
        }
        if (q_left <= left && right <= q_right) {
            lazy[node] += value;
            down(node, left, right);
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, q_left, q_right, value);
        update(node*2 + 1, mid + 1, right, q_left, q_right, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    long long get(int node, int left, int right, int q_left, int q_right) {
        down(node, left, right);
        if (left > q_right or q_left > right) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            down(node, left, right);
            return tree[node];
        }
        int mid = (left + right) / 2;
        long long get_left = get(node*2, left, mid, q_left, q_right);
        long long get_right = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return get_left + get_right;
    }
};

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        using pii = pair<int, int>;
        unordered_map<int, vector<pii>> pos;
        const int m = queries.size();
        
        for (int i = 0; i < m; ++i) {
            vector<int> q = queries[i];
            int l = q[0];
            int r = q[1];
            pos[r].push_back({l, i});
        }
        
        const int n = s.size();
        
        SegmentTree st(n);
        int cnt_z = 0, cnt_o = 0;
        vector<long long> ans(m);
        
        for (int l = 0, r = 0; r < n; ++r) {
            cnt_z += s[r] == '0';
            cnt_o += s[r] != '0';
            while (cnt_z > k && cnt_o > k) {
                cnt_z -= s[l] == '0';
                cnt_o -= s[l] != '0';
                l++;
            }
            st.update(1, 0, n - 1, l, r, 1);
            for (auto [ql, idx] : pos[r]) {
                ans[idx] = st.get(1, 0, n - 1, ql, r);
            }
        }
        
        return ans;
    }
};