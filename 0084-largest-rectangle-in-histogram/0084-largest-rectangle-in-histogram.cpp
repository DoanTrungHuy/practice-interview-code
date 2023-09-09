class SegmentTree {
private:
    vector<int> tree, heights;
    int n;
    
public:
    SegmentTree() {
        
    }
    
    SegmentTree(vector<int> heights) {
        this->heights = heights;
        this->n = heights.size();
        tree.resize(4*n);
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i);
        }
    }
    
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
        if (heights[tree[node*2]] < heights[tree[node*2 + 1]]) {
            tree[node] = tree[node*2];
        }
        else {
            tree[node] = tree[node*2 + 1];
        }
    }
    
    int get_node(int node, int left, int right, int q_left, int q_right) {
        if (q_right < left or right < q_left) {
            return -1;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_node(node*2, left, mid, q_left, q_right);
        int right_node = get_node(node*2 + 1, mid + 1, right, q_left, q_right);
        if (left_node == -1) {
            return right_node;
        }
        if (right_node == -1) {
            return left_node;
        }
        if (heights[left_node] < heights[right_node]) {
            return left_node;
        }
        else {
            return right_node;
        }
    }
    
    int get_node(int q_left, int q_right) {
        return get_node(1, 0, n - 1, q_left, q_right);
    }
};

class Solution {
private:
    vector<int> heights;
    SegmentTree st;
    
public:
    int rec(int left, int right) {
        if (right < left) {
            return 0;
        }
        int mid = st.get_node(left, right);
        return max({
            heights[mid] * (right - left + 1),
            rec(left, mid - 1),
            rec(mid + 1, right)
        });
    }
    
    int largestRectangleArea(vector<int>& heights) {
        this->heights = heights;
        SegmentTree st(heights);
        this->st = st;
        return rec(0, heights.size() - 1);
    }
};