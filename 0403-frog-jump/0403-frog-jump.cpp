int memo[2001][2001];

class Solution {
private:
    vector<int> stones;
    unordered_map<int, int> um;
    int n;
    
public:
    int dp(int i, int k) {
        if (i >= n or i < 0 or k <= 0) {
            return 0;
        }
        if (i == n - 1) {
            return 1;
        }
        if (memo[i][k] != -1) {
            return memo[i][k];
        }
        int ans = 0;
        if (i == 0) {
            if (um.count(stones[i] + k)) {
                return memo[i][k] = dp(stones[i] + k, k);
            }
        }
        else {
            for (int j = -1; j <= 1; ++j) {
                if (!um.count(stones[i] + k + j)) {
                    continue;
                }
                ans |= dp(um[stones[i] + k + j], k + j);
            }
        }
        return memo[i][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        this->stones = stones;
        this->n = stones.size();
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; ++i) {
            um[stones[i]] = i;
        }
        return dp(0, 1) > 0;
    }
};