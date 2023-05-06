int memo[41][1 << 10];
const int MOD = 1e9 + 7;

class Solution {
private:
    vector<vector<int>> hats;
    int m;
    vector<vector<int>> people;
    int allMask;
    
public:
    int dp(int hat, int mask) {
        if (mask == allMask) {
            return 1;
        }
        if (hat > 40) {
            return 0;
        }
        if (memo[hat][mask] != -1) {
            return memo[hat][mask];
        }
        int res = dp(hat + 1, mask);
        for (int p : people[hat]) {
            if ((1 << p) & mask) {
                continue;
            }
            res = (res + dp(hat + 1, mask | (1 << p))) % MOD;
        }
        return memo[hat][mask] = res;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(memo, -1, sizeof(memo));
        this->hats = hats;
        m = hats.size();
        allMask = (1 << m) - 1;
        people.resize(41);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < hats[i].size(); ++j) {
                people[hats[i][j]].push_back(i);
            }
        }
        return dp(1, 0);
    }
};