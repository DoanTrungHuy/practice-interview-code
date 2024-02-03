int memo[501];

class Solution {
private:
    vector<int> arr;
    int k, n;
    vector<int> tree;
    
public:
    void update(int node, int left, int right, int index, int value) {
        if (index < left or index > right) {
            return;
        }    
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
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
    
    int dp(int i) {
        if (i >= n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = INT_MIN;
        for (int j = 1; j <= k; ++j) {
            ans = max(ans, dp(i + j) + get(1, 0, n - 1, i, min(i + j - 1, n - 1))*min(j, n - i));
        }
        return memo[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memo, -1, sizeof(memo));
        this->arr = arr;
        this->k = k;
        this->n = arr.size();
        tree.resize(n*4);
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i, arr[i]);
        }
        return dp(0);
    }
};