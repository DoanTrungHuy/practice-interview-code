int memo[101][101];
int cost[101][101];
int pref[101];

class Solution {
private:
    vector<int> h;
    int n;
    
public:
    int dp(int i, int k) {
        if (k < 0) {
            return 1e9;
        }
        if (i == n) {
            if (k == 0) {
                return 0;
            }
            else {
                return 1e9;
            }
        }
        if (memo[i][k] != -1) {
            return memo[i][k];
        }
        int ans = 1e9;
        for (int j = i; j < (int)h.size(); ++j) {
            ans = min(ans, dp(j + 1, k - 1) + cost[i][j]);
        }
        return memo[i][k] = ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        this->h = houses;
        this->n = (int)h.size();
        memset(memo, -1, sizeof(memo));
        memset(cost, +0, sizeof(cost));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    cost[i][j] += abs(h[k] - h[(i + j) / 2]);
                }
            }
        }
        return dp(0, k);
    }
};