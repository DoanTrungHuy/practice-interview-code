const int MOD = 1e9 + 7;
const int MAX_INV = 400;

class Solution {
private:
    int dp[301][401];
    unordered_map<int, int> reqs;
    
    int solve(int pos, int inv, int n) {
        if (reqs.count(pos - 1) && reqs[pos - 1] != inv) {
            return 0;
        }
        
        if (pos == n) {
            return 1;
        }

        if (inv > MAX_INV) {
            return 0;
        }

        if (dp[pos][inv] != -1) {
            return dp[pos][inv];
        }
        
        int res = 0;
        for (int k = 0; k <= pos; k++) {
            int new_inv = inv + (pos - k);
            res = (res + solve(pos + 1, new_inv, n)) % MOD;
        }
        
        return dp[pos][inv] = res;
    }

public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        memset(dp, -1, sizeof(dp));
        for (auto& r : requirements) {
            reqs[r[0]] = r[1];
        }
        return solve(0, 0, n);
    }
};