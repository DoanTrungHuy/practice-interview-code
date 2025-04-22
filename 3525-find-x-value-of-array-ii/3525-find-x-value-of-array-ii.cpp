struct Node {
    int subProd;
    int remainder[5];

    Node() {
        memset(remainder, 0, sizeof(remainder));
        subProd = 1;
    }
};

struct SegmentTree {
    vector<Node> nodes;
    int k;

    SegmentTree() {

    }

    SegmentTree(int n, int k) {
        nodes.resize(4*n);
        this->k = k;
    }

    Node merge(Node nodeL, Node nodeR) {
        Node newNode = Node();
        newNode.subProd = (nodeL.subProd * nodeR.subProd) % k;

        for (int r = 0; r < k; ++r) {
            newNode.remainder[r] += nodeL.remainder[r];
            newNode.remainder[(nodeL.subProd * r) % k] += nodeR.remainder[r];
        }

        return newNode;
    }

    void update(int id, int left, int right, int index, int value) {
        if (index < left || right < index) {
            return;
        }
        if (left == right) {
            Node newNode = Node();
            newNode.subProd = value;
            newNode.remainder[value] = 1;
            nodes[id] = newNode;
            return;
        }
        int mid = (left + right) >> 1;
        update(id*2, left, mid, index, value);
        update(id*2 + 1, mid + 1, right, index, value);
        nodes[id] = merge(nodes[id*2], nodes[id*2 + 1]);
    }

    Node get(int id, int left, int right, int q_left, int q_right) {
        if (q_left > right || left > q_right) {
            return Node();
        }
        if (q_left <= left && right <= q_right) {
            return nodes[id];
        }
        int mid = (left + right) >> 1;
        Node nodeL = get(id*2, left, mid, q_left, q_right);
        Node nodeR = get(id*2 + 1, mid + 1, right, q_left, q_right);
        return merge(nodeL, nodeR);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        for (int &num : nums) {
            num = num % k;
        }

        for (auto &query : queries) {
            query[1] = query[1] % k;
        }

        const int n = nums.size();

        SegmentTree st(n, k);

        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, i, nums[i]);
        }

        vector<int> result;

        for (const auto query : queries) {
            // [index, value, start, x]
            int index = query[0];
            int value = query[1];
            int start = query[2];
            int x = query[3];
            st.update(1, 0, n - 1, index, value);
            int cnt = st.get(1, 0, n - 1, start, n - 1).remainder[x];
            result.push_back(cnt);
        }

        return result;
    }
};