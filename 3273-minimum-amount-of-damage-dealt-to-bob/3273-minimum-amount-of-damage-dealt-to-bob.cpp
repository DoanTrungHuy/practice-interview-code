class SegmentTree {
public:
    vector<int> tree;
    
    SegmentTree(int n = 0) {
        tree.resize(4*n);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (left > index || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || left > q_right) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
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
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        const int n = damage.size();
        using tp = tuple<double, int, int>;
        priority_queue<tp> pq;
        SegmentTree st(n);
        
        // 62 [80,79] [86,13]
        // AC đi PLS

        for (int i = 0; i < n; ++i) {
            double damage_per_time = static_cast<double>(damage[i]) / static_cast<double>((health[i] + power - 1) / power);
            pq.push({damage_per_time, health[i], i});
            st.update(1, 0, n - 1, i, damage[i]);
        }
        
        long long ans = 0;
        
        while (!pq.empty()) {
            auto [damage_per_time, health_left, i] = pq.top();
            pq.pop();
            
            ans += ((health_left + power - 1) / power) * st.get(1, 0, n - 1, 0, n - 1);
            
            st.update(1, 0, n - 1, i, 0);
        }

        return ans;
    }
};
