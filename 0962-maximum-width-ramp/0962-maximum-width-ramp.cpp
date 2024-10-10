const int INF = 1e9;

class SegmentTree {
private:
    vector<int> tree;
    
public:    
    SegmentTree(int n) {
        tree.resize(4*n, INF);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (index < left || right < index) {
            return;
        }
        if (left == right) {
            tree[node] = min(tree[node], value);
            return;
        }
        int mid = (left + right) >> 1;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = min(tree[node*2], tree[node*2 + 1]);
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return INF;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return min(left_node, right_node);
    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int n = nums.size();
        SegmentTree st(n);
        map<int, int> cp;
        
        for (const int num : nums) {
            cp[num];
        }
        
        int times = 0;
        
        for (auto &[v, c] : cp) {
            c = times++;
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, i - st.get(1, 0, times, 0, cp[nums[i]]));
            st.update(1, 0, times, cp[nums[i]], i);
        }
        
        return ans;
    }
};