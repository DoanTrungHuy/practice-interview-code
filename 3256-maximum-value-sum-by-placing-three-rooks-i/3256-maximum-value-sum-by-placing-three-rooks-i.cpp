class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        const int m = board.size(), n = board[0].size();
        vector<vector<long long>> row(m, vector<long long>(3, LLONG_MIN));
        vector<vector<int>> col(m, vector<int>(3, -1));

        long long max_sum = LLONG_MIN;

        for (int i = 0; i < m; ++i) {
            vector<pair<long long, int>> col_values;

            for (int j = 0; j < n; ++j) {
                col_values.emplace_back(board[i][j], j);
            }

            sort(col_values.begin(), col_values.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
                return a.first > b.first;
            });

            for (int k = 0; k < 3; ++k) {
                auto [r, c] = col_values[k];
                row[i][k] = r;
                col[i][k] = c;
            }
        }

        for (int i1 = 0; i1 < m; ++i1) {
            for (int i2 = i1 + 1; i2 < m; ++i2) {
                for (int i3 = i2 + 1; i3 < m; ++i3) {
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            if (col[i2][j] == col[i1][i]) {
                                continue;
                            }
                            for (int k = 0; k < 3; ++k) {
                                if (col[i3][k] != col[i2][j] && col[i3][k] != col[i1][i]) {
                                    long long c_sum = row[i1][i] + row[i2][j] + row[i3][k];
                                    max_sum = max(max_sum, c_sum);
                                }
                            }
                        }
                    }
                }
            }
        }

        return max_sum;
    }
};
