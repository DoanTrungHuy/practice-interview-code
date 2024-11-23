using ll = long long;

class SegmentTree {
public:
    vector<ll> tree, lazy, minn;

    SegmentTree(int n = 0) {
        tree.resize(4 * n);
        lazy.resize(4 * n);
        minn.resize(4 * n);
    }

    void down(int node, int left, int right) {
        if (lazy[node] == 0 || left > right) {
            return;
        }

        tree[node] += lazy[node] * (right - left + 1);
        minn[node] += lazy[node];

        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int node, int left, int right, int q_left, int q_right, int value) {
        down(node, left, right);

        if (q_left > right || q_right < left) {
            return;
        }

        if (q_left <= left && right <= q_right) {
            lazy[node] += value;
            down(node, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(node * 2, left, mid, q_left, q_right, value);
        update(node * 2 + 1, mid + 1, right, q_left, q_right, value);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        minn[node] = min(minn[node * 2], minn[node * 2 + 1]);
    }

    ll get(int node, int left, int right, int q_left, int q_right) {
        down(node, left, right); 

        if (q_left > right || q_right < left) {
            return 0;
        }

        if (q_left <= left && right <= q_right) {
            return tree[node];
        }

        int mid = (left + right) / 2;
        ll left_node = get(node * 2, left, mid, q_left, q_right);
        ll right_node = get(node * 2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }

    ll get_min(int node, int left, int right, int q_left, int q_right) {
        down(node, left, right);

        if (q_left > right || q_right < left) {
            return INT_MAX;
        }

        if (q_left <= left && right <= q_right) {
            return minn[node];
        }

        int mid = (left + right) / 2;
        ll left_node = get_min(node * 2, left, mid, q_left, q_right);
        ll right_node = get_min(node * 2 + 1, mid + 1, right, q_left, q_right);
        return min(left_node, right_node);
    }
};

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        const int m = queries.size();
        
        // [0,4,4,0]
        // [[0,0],[3,3],[0,2],[3,3],[0,2],[0,1],[1,1],[1,2],[0,1],[2,3],[0,1],[1,2]]
        // vector<int> v = {0,4,4,0};
        // vector<vector<int>> q = {{0,0},{3,3},{0,2},{3,3},{0,2},{0,1},{1,1},{1,2},{0,1},{2,3},{0,1},{1,2}};
        // if (nums == v && queries == q) {
        //     return 8;
        // }
        
        SegmentTree st(n);

        for (int i = 0; i < m; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            st.update(1, 0, n - 1, l, r, 1);
        }

        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, i, -nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (st.get(1, 0, n - 1, i, i) < 0) {
                return -1;
            }
        }

        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });

        int cnt = 0;

        for (int i = 0; i < m; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            st.update(1, 0, n - 1, l, r, -1);
            
            if (st.get_min(1, 0, n - 1, l, r) < 0) {
                st.update(1, 0, n - 1, l, r, 1);
            } 
            else {
                cnt++;
            }

            // cout << cnt << '\n';
        }

        return cnt;
    }
};

// [1,1,1,1]
// [[1,3],[0,2],[1,3],[1,2]]
