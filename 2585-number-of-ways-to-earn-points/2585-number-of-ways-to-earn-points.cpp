const int mod = 1e9 + 7;

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    
    int dfs(int i, int marks, int target, vector<vector<int>>& types) {
        if (target == marks) {
            return 1;
        }
        if (marks > target or i >= n) {
            return 0;
        }
        if (dp[i][marks] != -1) {
            return dp[i][marks];
        }
        long long cnt = 0;
        for (int j = 0; j <= types[i][0]; ++j) {
            cnt += dfs(i + 1, j * types[i][1] + marks, target, types);
            cnt %= mod;
        }
        return dp[i][marks] = cnt;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        dp.resize(n, vector<int>(target + 1, -1));
        return dfs(0, 0, target, types);
    }
};