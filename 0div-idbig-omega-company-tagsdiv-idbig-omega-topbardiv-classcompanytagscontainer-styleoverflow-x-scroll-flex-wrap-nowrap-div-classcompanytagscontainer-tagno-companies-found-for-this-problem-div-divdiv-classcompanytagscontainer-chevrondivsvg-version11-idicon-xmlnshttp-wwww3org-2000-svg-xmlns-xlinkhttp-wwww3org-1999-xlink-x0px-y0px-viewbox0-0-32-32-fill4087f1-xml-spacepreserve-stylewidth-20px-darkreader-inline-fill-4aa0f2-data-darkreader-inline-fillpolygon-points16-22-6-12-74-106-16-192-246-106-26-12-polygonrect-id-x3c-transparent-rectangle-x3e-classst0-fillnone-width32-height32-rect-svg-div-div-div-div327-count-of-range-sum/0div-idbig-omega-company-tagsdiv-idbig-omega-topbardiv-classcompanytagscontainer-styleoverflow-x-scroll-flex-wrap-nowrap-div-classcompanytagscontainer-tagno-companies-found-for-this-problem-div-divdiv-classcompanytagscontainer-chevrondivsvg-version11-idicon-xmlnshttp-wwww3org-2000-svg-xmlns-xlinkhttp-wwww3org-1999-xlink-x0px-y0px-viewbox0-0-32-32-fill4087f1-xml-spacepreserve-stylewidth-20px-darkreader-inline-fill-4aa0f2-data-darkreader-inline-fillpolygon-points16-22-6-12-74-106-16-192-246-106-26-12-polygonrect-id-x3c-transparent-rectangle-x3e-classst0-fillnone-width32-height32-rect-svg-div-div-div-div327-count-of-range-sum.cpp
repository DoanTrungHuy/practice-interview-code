class Solution {
private:
    vector<long long> tree, pref;
    int n;
    
public:
    void update(int node, int left, int right, int index, int value) {
        if (index < left or right < index) {
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
        if (q_left > right or left > q_right) {
            return 0;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->n = nums.size();
        tree.resize(n*4);
        pref.resize(n + 1);
        
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        set<long long> t_nums(pref.begin(), pref.end());
        
        vector<long long> unq_nums(t_nums.begin(), t_nums.end());
        
        int ans = 0;
        
        for (int i = 0; i <= n; ++i) {
            int l = lower_bound(unq_nums.begin(), unq_nums.end(), pref[i] - upper) - unq_nums.begin();
            int r = upper_bound(unq_nums.begin(), unq_nums.end(), pref[i] - lower) - unq_nums.begin();
            int ci = lower_bound(unq_nums.begin(), unq_nums.end(), pref[i]) - unq_nums.begin();
            ans += get(1, 0, n, l, r - 1);
            update(1, 0, n, ci, 1 + get(1, 0, n, ci, ci));
        }
        
        return ans;
    }
};