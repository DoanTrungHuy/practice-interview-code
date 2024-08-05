struct SegmentTree {
    vector<int> tree;
    vector<int> a;
    
    SegmentTree() {}
    
    SegmentTree(vector<int> a) {
        this->a = a;
        const int n = a.size();
        tree.resize(4*n, -1);
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i);
        }
    }
    
    void update(int node, int left, int right, int index) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = index;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index);
        update(node*2 + 1, mid + 1, right, index);
        if (tree[node*2] == -1) {
            tree[node] = tree[node*2 + 1];
        }
        else if (tree[node*2 + 1] == -1) {
            tree[node] = tree[node*2];
        }
        else {
            if (a[tree[node*2]] < a[tree[node*2 + 1]]) {
                tree[node] = tree[node*2];
            }
            else {
                tree[node] = tree[node*2 + 1];
            }
        }
    }
    
    int get_idx(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return -1;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_idx(node*2, left, mid, q_left, q_right);
        int right_node = get_idx(node*2 + 1, mid + 1, right, q_left, q_right);
        if (left_node == -1) {
            return right_node;
        }
        else if (right_node == -1) {
            return left_node;
        }
        else {
            if (a[left_node] < a[right_node]) {
                return left_node;
            }
            else {
                return right_node;
            }
        }
    }
};

class Solution {
private:
    SegmentTree st;
    int n;
    vector<int> target;
    
public:
    int daq(int left, int right, int prev_min) {
        if (left > right) {
            return 0;
        }
        int mid = st.get_idx(1, 0, n - 1, left, right);
        int ans = target[mid] - prev_min;
        ans += daq(left, mid - 1, target[mid]);
        ans += daq(mid + 1, right, target[mid]);
        return ans;
    }
    
    int minNumberOperations(vector<int>& target) {
        this->target = target;
        this->n = target.size();
        st = SegmentTree(target);
        return daq(0, n - 1, 0);
    }
};