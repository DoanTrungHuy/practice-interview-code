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
        return max(left_node, right_node);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        const int MAX_VAL = 10001;
        
        tree.resize(MAX_VAL*8, 0);
        
        for (int i = 0; i < n; ++i) {
            int g = get(1, 0, 2*MAX_VAL, 0, nums[i] - 1 + MAX_VAL) + 1;
            update(1, 0, 2*MAX_VAL, nums[i] + MAX_VAL, g);
        }
        
        return tree[1];
    }
};