class Solution {
private:
    vector<int> tree;
    
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
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get_max(int node, int left, int right, int q_left, int q_right) {
        if (right < q_left or q_right < left) {
            return 0;
        }    
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_max(node*2, left, mid, q_left, q_right);
        int right_node = get_max(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
    
    long long numberOfSubarrays(vector<int>& nums) {
        const int n = nums.size();
        tree.resize(4*n);
        unordered_map<int, vector<int>> um;
        
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i, nums[i]);
            um[nums[i]].push_back(i);
        }
        
        long long ans = 0;
        
        for (auto &[num, vec_num] : um) {
            long long cnt = 1;
            int prev_idx = vec_num[0];
            const int m = vec_num.size();
            ans += m;
            
            for (int i = 1; i < m; ++i) {
                if (get_max(1, 0, n - 1, prev_idx, vec_num[i]) == num) {
                    cnt++;
                }
                else {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 1;
                    prev_idx = vec_num[i];
                }
            }
            
            ans += cnt * (cnt - 1) / 2;
        }
        
        return ans;
    }
};