class SegmentTree {
private:
    vector<int> tree;
    
public:
    SegmentTree(int n = 0) {
        tree.resize(4*(n + 1), INT_MAX);
    }
    
    void update(int node, int left, int right, int index, int value) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (right + left) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = min(tree[node*2], tree[node*2 + 1]);
    }
    
    int get_min(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
            return INT_MAX;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (right + left) / 2;
        int left_node = get_min(node*2, left, mid, q_left, q_right);
        int right_node = get_min(node*2 + 1, mid + 1, right, q_left, q_right);
        return min(left_node, right_node);
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        SegmentTree vers[n], hors[m];
        
        for (int i = 0; i < n; ++i) {
            SegmentTree st(m);
            vers[i] = st;
        }
        
        for (int i = 0; i < m; ++i) {
            SegmentTree st(n);
            hors[i] = st;
        }
        
        int dp[n][m];
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 and j == m - 1) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = INT_MAX;
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    int right_reward = vers[i].get_min(1, 0, m - 1, j + 1, min(grid[i][j] + j, m - 1));
                    int down_reward = hors[j].get_min(1, 0, n - 1, i + 1, min(grid[i][j] + i, n - 1));
                    if (right_reward == INT_MAX and down_reward == INT_MAX) {
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], 1 + min(right_reward, down_reward));
                }
                vers[i].update(1, 0, m - 1, j, dp[i][j]);
                hors[j].update(1, 0, n - 1, i, dp[i][j]);
            }
        }
        
        return dp[0][0] == INT_MAX ? -1 : dp[0][0];
    }
};