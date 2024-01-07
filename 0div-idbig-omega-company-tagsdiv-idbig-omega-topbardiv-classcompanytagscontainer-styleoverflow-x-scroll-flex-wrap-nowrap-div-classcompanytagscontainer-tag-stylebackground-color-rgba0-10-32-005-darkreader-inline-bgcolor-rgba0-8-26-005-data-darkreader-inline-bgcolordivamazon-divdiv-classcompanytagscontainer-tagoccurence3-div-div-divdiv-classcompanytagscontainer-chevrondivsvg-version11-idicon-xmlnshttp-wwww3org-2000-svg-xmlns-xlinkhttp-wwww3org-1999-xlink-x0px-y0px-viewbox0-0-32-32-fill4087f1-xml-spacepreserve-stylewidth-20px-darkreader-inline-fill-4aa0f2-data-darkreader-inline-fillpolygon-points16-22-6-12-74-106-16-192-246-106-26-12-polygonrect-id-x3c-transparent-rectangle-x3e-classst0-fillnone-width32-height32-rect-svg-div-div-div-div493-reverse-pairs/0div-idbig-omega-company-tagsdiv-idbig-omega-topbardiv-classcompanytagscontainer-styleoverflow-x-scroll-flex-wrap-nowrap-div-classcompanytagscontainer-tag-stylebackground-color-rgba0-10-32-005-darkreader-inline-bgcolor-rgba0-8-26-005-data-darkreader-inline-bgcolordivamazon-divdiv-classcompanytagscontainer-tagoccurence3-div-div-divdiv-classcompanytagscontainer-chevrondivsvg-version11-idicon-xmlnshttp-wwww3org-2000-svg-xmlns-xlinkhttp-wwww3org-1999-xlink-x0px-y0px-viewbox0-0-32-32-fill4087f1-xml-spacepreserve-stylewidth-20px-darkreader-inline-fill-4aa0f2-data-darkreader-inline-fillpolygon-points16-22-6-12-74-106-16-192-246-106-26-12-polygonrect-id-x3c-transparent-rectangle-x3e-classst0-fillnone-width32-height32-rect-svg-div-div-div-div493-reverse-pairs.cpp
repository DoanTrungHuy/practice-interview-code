class Solution {
private:
    vector<int> tree;
    
public:
    void update(int node, int left, int right, int index, int value) {
        if (index < left or right < index) {
            return;
        }
        if (left == right) {
            tree[node] += value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (left > q_right or q_left > right) {
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
    
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        const int MAX_VAL = 1e6;
        int ans = 0;
        tree.resize(MAX_VAL*4, 0);
        
        vector<long long> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        
        for (int i = 0; i < n; ++i) {
            int p_j = lower_bound(vals.begin(), vals.end(), (long long)nums[i]*2 + 1) - vals.begin();
            ans += get(1, 0, n, p_j, n);
            int p_i = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
            update(1, 0, n, p_i, 1);
        }
        
        return ans;
    }
};