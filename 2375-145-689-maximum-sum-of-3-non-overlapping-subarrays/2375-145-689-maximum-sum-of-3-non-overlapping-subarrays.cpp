struct SegmentTree {
private:
    vector<int> tree, nums;
    
public:
    SegmentTree() {
        
    }
    
    SegmentTree(int n, vector<int> &nums) {
        tree.resize(4*n, -1);
        this->nums = nums;
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i);
        }
    }
    
    void update(int node, int left, int right, int index) {
        if (index < left || right < index) {
            return;
        }
        if (left == right) {
            tree[node] = index;
            return;
        }
        int mid = (left + right) >> 1;
        update(node*2, left, mid, index);
        update(node*2 + 1, mid + 1, right, index);
        if (tree[node*2] == -1) {
            tree[node] = tree[node*2 + 1];
        }
        else if (tree[node*2 + 1] == -1) {
            tree[node] = tree[node*2];
        }
        else if (nums[tree[node*2]] >= nums[tree[node*2 + 1]]) {
            tree[node] = tree[node*2];
        }
        else {
            tree[node] = tree[node*2 + 1];
        }
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return -1;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        int node_left = get(node*2, left, mid, q_left, q_right);
        int node_right = get(node*2 + 1, mid + 1, right, q_left, q_right);
        if (node_left == -1) {
            return node_right;
        }
        else if (node_right == -1) {
            return node_left;
        }
        else if (nums[node_left] >= nums[node_right]) {
            return node_left;
        }
        else {
            return node_right;
        }
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        int s = 0;
        vector<int> nums1(n, -1), nums2(n, -1);
        
        for (int i = 0, j = 0; i < n; ++i) {
            s += nums[i];
            if (i - j + 1 == k) {
                nums1[i] = s;
                nums2[j] = s;
                s -= nums[j];
                j++;
            }
        }
        
        SegmentTree st_left(n, nums1), st_right(n, nums2);
                
        vector<int> ans;
        int max_val = 0;
        s = 0;
        
        for (int i = 0, j = 0; i < n; ++i) {
            s += nums[i];
            if (i - j + 1 == k) {
                int get_query_left = st_left.get(1, 0, n - 1, 0, max(0, j - 1));
                int get_query_right = st_right.get(1, 0, n - 1, min(n - 1, i + 1), n - 1);
                if (j >= k && i + k < n && get_query_left != -1 && get_query_right != -1 && \
                    nums1[get_query_left] != -1 && nums2[get_query_right] != -1) {
                    int val = s + nums1[get_query_left] + nums2[get_query_right];
                    if (max_val < val) {
                        max_val = val;
                        ans = {get_query_left - k + 1, j, get_query_right};
                    }
                }
                s -= nums[j];
                j++;
            }
        }
        
        return ans;
    }
};