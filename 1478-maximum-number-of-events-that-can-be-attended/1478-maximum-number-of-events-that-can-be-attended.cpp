struct SegmentTree {
    vector<int> nodes, nums;

    SegmentTree() {

    }

    SegmentTree(int n) {
        nodes.resize(4*n, -1);
        nums.resize(n, 0);
    }

    void update(int id, int left, int right, int index, int value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            nums[index] = value;
            nodes[id] = index;
            return;
        }
        int mid = (left + right) >> 1;
        update(id*2, left, mid, index, value);
        update(id*2 + 1, mid + 1, right, index, value);
        if (nodes[2*id + 1] == -1) {
            nodes[id] = nodes[2*id];
        }
        else if (nodes[2*id] == -1) {
            nodes[id] = nodes[2*id + 1];
        }
        else if (nums[nodes[2*id]] <= nums[nodes[2*id + 1]]) {
            nodes[id] = nodes[2*id]; 
        }
        else {
            nodes[id] = nodes[2*id + 1]; 
        }
    }

    int get(int id, int left, int right, int q_left, int q_right) {
        if (right < q_left || q_right < left) {
            return -1;
        }
        
        if (q_left <= left && right <= q_right) {
            return nodes[id];
        }

        int mid = (left + right) >> 1;
        int left_node = get(id*2, left, mid, q_left, q_right);
        int right_node = get(id*2 + 1, mid + 1, right, q_left, q_right);

        if (right_node == -1) {
            return left_node;
        }
        else if (left_node == -1) {
            return right_node;
        }
        else if (nums[left_node] <= nums[right_node]) {
            return left_node; 
        }
        else {
            return right_node; 
        }
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        const int MAX_SZ = 1e5;
        SegmentTree st(MAX_SZ + 1);

        /// ----------
        //      -----
        //         ------
        //         --
        
        sort(events.begin(), events.end(), [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        int ans = 0;

        for (int i = 0; i <= MAX_SZ; ++i) {
            st.update(1, 1, MAX_SZ, i, 0);
        }

        for (int i = 0; i < n; ++i) {
            int start = events[i][0];
            int end = events[i][1];

            int day = st.get(1, 1, MAX_SZ, start, end);

            if (st.nums[day] == 0) {
                ans++;
                st.update(1, 1, MAX_SZ, day, 1);
            }
        }

        return ans;
    }
};