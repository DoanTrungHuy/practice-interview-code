using ll = long long;

class SegmentTree {
public:
    SegmentTree(ll n) : n(n), MIN_VAL(-1e9) {
        tree.resize(4 * n, MIN_VAL);
    }

    void update(ll node, ll left, ll right, ll index, ll value) {
        if (index < left || index > right) {
            return;
        }

        if (left == right) {
            tree[node] = value;
            return;
        }

        ll mid = (left + right) / 2;

        update(node * 2, left, mid, index, value);
        update(node * 2 + 1, mid + 1, right, index, value);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    ll get_max(ll node, ll left, ll right, ll q_left, ll q_right) {
        if (q_left > right || q_right < left) {
            return MIN_VAL;
        }

        if (q_left <= left && right <= q_right) {
            return tree[node];
        }

        ll mid = (left + right) / 2;

        ll left_node = get_max(node * 2, left, mid, q_left, q_right);
        ll right_node = get_max(node * 2 + 1, mid + 1, right, q_left, q_right);

        return max(left_node, right_node);
    }

private:
    ll n;
    ll MIN_VAL;
    vector<ll> tree;
};

class Solution {
public:
    ll maximumValueSum(vector<vector<int>>& board) {
        ll m = board.size();
        ll n = board[0].size();

        long long max_sum = -1e18;

        vector<vector<pair<ll, ll>>> top3(m);

        for (ll i = 0; i < m; ++i) {
            vector<pair<ll, ll>> tmp;
            for (ll j = 0; j < n; ++j) {
                tmp.emplace_back(board[i][j], j);
            }
            sort(tmp.rbegin(), tmp.rend());
            top3[i] = vector<pair<ll, ll>>(tmp.begin(), tmp.begin() + 3);
        }

        vector<SegmentTree> suf_col_seg;
        for (ll i = 0; i <= m; ++i) {
            suf_col_seg.emplace_back(n);
        }

        vector<ll> col_max(n, -1e9);

        for (ll i = m - 1; i >= 0; --i) {
            for (ll j = 0; j < n; ++j) {
                col_max[j] = max(col_max[j], 1LL*board[i][j]);
                suf_col_seg[i].update(1, 0, n - 1, j, col_max[j]);
            }
        }

        for (ll i1 = 0; i1 < m - 2; ++i1) {
            for (ll i2 = i1 + 1; i2 < m - 1; ++i2) {
                for (auto& [v1, j1] : top3[i1]) {
                    for (auto& [v2, j2] : top3[i2]) {
                        if (j1 != j2) {
                            ll i3 = i2 + 1;

                            ll left = min(j1, j2);
                            ll right = max(j1, j2);

                            ll v3 = -1e9;

                            if (left - 1 >= 0) {
                                v3 = max(v3, suf_col_seg[i3].get_max(1, 0, n - 1, 0, left - 1));
                            }

                            if (right + 1 < n) {
                                v3 = max(v3, suf_col_seg[i3].get_max(1, 0, n - 1, right + 1, n - 1));
                            }

                            if (left + 1 < right) {
                                v3 = max(v3, suf_col_seg[i3].get_max(1, 0, n - 1, left + 1, right - 1));
                            }

                            max_sum = max(max_sum, (long long)v1 + v2 + v3);
                        }
                    }
                }
            }
        }

        return max_sum;
    }
};