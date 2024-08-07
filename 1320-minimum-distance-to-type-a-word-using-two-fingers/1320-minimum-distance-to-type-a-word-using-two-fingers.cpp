using pii = pair<int, int>;

class Solution {
public:
    vector<pii> coordinates;
    int n;
    int memo[301][26][26][2];

    Solution() {
        memset(memo, -1, sizeof(memo));
    }

    int distance(int a, int b) {
        auto [x1, y1] = coordinates[a];
        auto [x2, y2] = coordinates[b];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dp(int i, int f1, int f2, int k, const string& word) {
        if (i == n) {
            return 0;
        }
        if (memo[i][f1][f2][k] != -1) {
            return memo[i][f1][f2][k];
        }

        int ans = 1e9;
        if (k == 1) {
            ans = min(ans, dp(i + 1, f1, word[i] - 'A', k - 1, word));
        }
        ans = min(ans, dp(i + 1, word[i] - 'A', f2, k, word) + distance(word[i] - 'A', f1));
        if (k == 0) {
            ans = min(ans, dp(i + 1, f1, word[i] - 'A', k, word) + distance(word[i] - 'A', f2));
        }

        return memo[i][f1][f2][k] = ans;
    }

    int minimumDistance(string word) {
        n = word.size();
        coordinates.resize(26);
        for (int i = 0; i < 26; ++i) {
            coordinates[i] = {i / 6, i % 6};
        }
        return dp(1, word[0] - 'A', word[0] - 'A', 1, word);
    }
};
