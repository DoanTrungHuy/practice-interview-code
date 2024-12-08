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
            tree[node] = max(tree[node], value);
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
    int maxTwoEvents(vector<vector<int>>& events) {
        const int n = events.size();
        using pii = pair<int, int>;
        
        sort(events.begin(), events.end(), [&](vector<int> a, vector<int> b) {
            if (a[1] == b[1]) {
                return a[2] < b[2];
            }
            return a[1] < b[1]; 
        });
        
        map<int, int> compress;
        
        for (int i = 0; i < n; ++i) {
            int s = events[i][0];
            int e = events[i][1];
            int v = events[i][2];
            compress[s];
            compress[e];
        }
        
        int times = 0;
        
        for (auto &[k, v] : compress) {
            v = ++times;
        }
        
        SegmentTree st(times);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int s = events[i][0];
            int e = events[i][1];
            int v = events[i][2];
            ans = max(ans, v + st.get(1, 1, times, 1, compress[s] - 1));
            st.update(1, 1, times, compress[e], v);
        }
        return ans;
    }
};