class SegmentTree {
    int[] tree;
    
    SegmentTree() {
        
    }
    
    public void resize(int n) {
        tree = new int[4 * n];
    }
    
    public void update(int node, int left, int right, int index, int value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) >> 1;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] | tree[node*2 + 1];
    }
    
    public int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node | right_node;
    }
}

class Solution {
    int[] nums;
    int k;
    SegmentTree st;
    
    public boolean f(int len) {
        final int n = nums.length;
        for (int i = 0, j = 0; i < n; ++i) {
            if (i - j + 1 == len) {
                if (st.get(1, 0, n - 1, j, i) >= k) {
                    return true;
                }
                j++;
            }
        }
        return false;
    }
    
    public int minimumSubarrayLength(int[] nums, int k) {
        this.nums = nums;
        this.k = k;
        final int n = nums.length;
        st = new SegmentTree();
        st.resize(n);
        
        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, nums[i]);
        }

        int left = 1;
        int right = n;
        int ans = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (f(mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
}