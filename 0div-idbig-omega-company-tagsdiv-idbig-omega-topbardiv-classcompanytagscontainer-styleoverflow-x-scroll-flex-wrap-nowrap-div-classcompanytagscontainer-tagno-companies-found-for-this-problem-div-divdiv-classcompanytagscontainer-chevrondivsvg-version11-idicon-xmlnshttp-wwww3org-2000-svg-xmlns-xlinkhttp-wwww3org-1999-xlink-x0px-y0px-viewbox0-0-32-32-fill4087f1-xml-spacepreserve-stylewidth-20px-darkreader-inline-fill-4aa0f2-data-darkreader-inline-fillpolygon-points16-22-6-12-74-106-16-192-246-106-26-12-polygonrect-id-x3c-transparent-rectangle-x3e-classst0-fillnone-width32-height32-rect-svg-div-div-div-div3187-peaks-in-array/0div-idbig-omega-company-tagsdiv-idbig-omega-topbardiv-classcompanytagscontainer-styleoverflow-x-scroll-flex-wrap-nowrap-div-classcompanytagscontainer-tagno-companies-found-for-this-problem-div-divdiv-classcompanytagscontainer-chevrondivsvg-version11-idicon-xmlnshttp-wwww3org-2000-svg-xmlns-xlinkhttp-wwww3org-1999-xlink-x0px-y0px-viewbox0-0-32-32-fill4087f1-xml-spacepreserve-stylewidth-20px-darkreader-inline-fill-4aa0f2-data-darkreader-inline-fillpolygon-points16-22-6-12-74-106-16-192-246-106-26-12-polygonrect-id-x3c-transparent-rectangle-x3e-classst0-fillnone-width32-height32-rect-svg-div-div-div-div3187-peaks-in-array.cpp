class Solution {
private:
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
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
    
    int get_sum(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
            return 0;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_sum(node*2, left, mid, q_left, q_right);
        int right_node = get_sum(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        tree.resize(4*n);
        vector<bool> peak(n);
        
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
                update(1, 0, n - 1, i, 1);
                peak[i] = 1;
            }
        }
        
        vector<int> ans;
        
        for (auto q : queries) {
            int choose = q[0];
            
            if (choose == 1) {
                int left = q[1];
                int right = q[2];
                ans.push_back(max(0, get_sum(1, 0, n - 1, left, right) - peak[left] - peak[right]));
            }
            else {
                int i = q[1], val = q[2];
                
                nums[i] = val;
                
                if (i - 1 >= 0 and i < n - 1) {
                    if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
                        peak[i] = 1;
                        update(1, 0, n - 1, i, 1);
                    }
                    else {
                        peak[i] = 0;
                        update(1, 0, n - 1, i, 0);
                    }
                }
                
                i--;
                
                if (i - 1 >= 0 and i < n - 1) {
                    if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
                        peak[i] = 1;
                        update(1, 0, n - 1, i, 1);
                    }
                    else {
                        peak[i] = 0;
                        update(1, 0, n - 1, i, 0);
                    }
                }
                
                i += 2;
                
                if (i - 1 >= 0 and i < n - 1) {
                    if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
                        peak[i] = 1;
                        update(1, 0, n - 1, i, 1);
                    }
                    else {
                        peak[i] = 0;
                        update(1, 0, n - 1, i, 0);
                    }
                }
            }
        }
        
        return ans;
    }
};