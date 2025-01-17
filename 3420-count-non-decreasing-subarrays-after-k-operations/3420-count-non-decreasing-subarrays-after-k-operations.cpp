class SegmentTree {
private:
    vector<int> tree, arr;

public:
    SegmentTree() {}

    SegmentTree(vector<int> arr) {
        this->arr = arr;
        int n = arr.size();
        tree.resize(4 * n, -1);
    }

    void update(int node, int left, int right, int index) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = index;
            return;
        }
        int mid = (left + right) >> 1;
        update(node * 2, left, mid, index);
        update(node * 2 + 1, mid + 1, right, index);
        if (tree[node * 2] == -1) {
            tree[node] = tree[node * 2 + 1];
        } else if (tree[node * 2 + 1] == -1) {
            tree[node] = tree[node * 2];
        } else {
            if (arr[tree[node * 2]] > arr[tree[node * 2 + 1]]) {
                tree[node] = tree[node * 2];
            } else {
                tree[node] = tree[node * 2 + 1];
            }
        }
    }

    int get_max(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || q_right < left) {
            return -1;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) >> 1;
        int left_node = get_max(node * 2, left, mid, q_left, q_right);
        int right_node = get_max(node * 2 + 1, mid + 1, right, q_left, q_right);
        if (left_node == -1) {
            return right_node;
        } else if (right_node == -1) {
            return left_node;
        } else {
            if (arr[left_node] > arr[right_node]) {
                return left_node;
            } else {
                return right_node;
            }
        }
    }
};

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        stack<int> st;
        vector<long long> suff(n + 1), pref;

        for (int i = 0; i < n; ++i) {
            if (pref.empty()) {
                pref.push_back(nums[i]);
            } else {
                pref.push_back(pref.back() + nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                suff[i] = 1LL*nums[i] * (n - i);
            } else {
                suff[i] = 1LL*nums[i] * (st.top() - i) + suff[st.top()];
            }
            st.push(i);
        }

        SegmentTree seg(nums);

        for (int i = 0; i < n; ++i) {
            seg.update(1, 0, n - 1, i);
        }

        long long ans = 0;

        auto get_ops = [&](int j, int i) {
            int index_of_value_largest = seg.get_max(1, 0, n - 1, j, i);
            int m = index_of_value_largest;

            long long sum_changes = suff[j] - suff[m] + 1LL*nums[m] * (i - m + 1);
            long long sum_original = pref[i] - (j - 1 < 0 ? 0 : pref[j - 1]);

            return sum_changes - sum_original;
        };

        for (int i = 0, j = 0; i < n; ++i) {
            while (j <= i && get_ops(j, i) > k) {
                j++;
            }
            ans += i - j + 1;
        }

        return ans;
    }
};
