const int MOD = 1e9 + 7;

class Solution {
private:
    vector<int> tree;
    vector<int> arr;
    int n;
    
public:
    void update(int node, int left, int right, int index) {
        if (index < left or index > right) {
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
        else if (arr[tree[node*2]] < arr[tree[node*2 + 1]]) {
            tree[node] = tree[node*2];
        }
        else {
            tree[node] = tree[node*2 + 1];
        }
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (left > q_right or q_left > right) {
            return -1;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        if (left_node == -1) {
            return right_node;
        }
        else if (right_node == -1) {
            return left_node;
        }
        else if (arr[left_node] < arr[right_node]) {
            return left_node;
        }
        return right_node;
    }
    
    long long dad(int left, int right) {
        if (left > right) {
            return 0;
        }
        int idx = get(1, 0, n - 1, left, right);
        if (idx == -1) {
            return 0;
        }
        long long s = ((long long)(idx - left + 1) * (right - idx + 1)) % MOD;
        (s *= arr[idx]) % MOD;
        (s += dad(left, idx - 1)) % MOD;
        (s += dad(idx + 1, right)) % MOD;
        return s;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        this->arr = arr;
        this->n = arr.size();
        tree.resize((n + 1) * 4, -1);
        
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i);
        }
        
        return (dad(0, n - 1) + MOD) % MOD;
    }
};