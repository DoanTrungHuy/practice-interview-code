struct SegmentTree {
    vector<long long> nodes;

    SegmentTree(int n) {
        nodes.resize(4*n);
    }

    void update(int id, int left, int right, int index, long long value) {
        if (index < left || right < index) {
            return;
        }
        if (left == right) {
            nodes[id] = max(nodes[id], value);
            return;
        }
        int mid = (left + right) >> 1;
        update(id*2, left, mid, index, value);
        update(id*2 + 1, mid + 1, right, index, value);
        nodes[id] = max(nodes[id*2], nodes[id*2 + 1]);
    }

    long long get(int id, int left, int right, int q_left, int q_right) {
        if (q_right < left || right < q_left) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            return nodes[id];
        }
        int mid = (left + right) >> 1;
        long long left_node = get(id*2, left, mid, q_left, q_right);
        long long right_node = get(id*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
};


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        // segment tree 2 cái

        // 1 cái truy vấn từ nums: 0 -> i - 1 cần tìm
        // 2 cái truy vấn từ nums: i + 1 -> n - 1 cần tìm
        
        const int n = nums.size();
        long long ans = 0;

        for (int num : nums) {
            ans = max(ans, 1LL*num);
        }

        long long max_n = ans;

        SegmentTree st1(ans), st2(ans);
        long long dp[n + 1][2];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            if (i - k >= 0) {
                st1.update(1, 0, max_n, nums[i - k], dp[i - k][0]);
                st2.update(1, 0, max_n, nums[i - k], dp[i - k][1]);
            }

            long long get1 = st1.get(1, 0, max_n, 0, nums[i] - 1);
            long long get2 = st2.get(1, 0, max_n, nums[i] + 1, max_n);

            dp[i][0] = get2 + nums[i];
            dp[i][1] = get1 + nums[i];

            ans = max({ans, dp[i][0], dp[i][1]});
        }

        return ans;
    }
};