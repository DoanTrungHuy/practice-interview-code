class Solution {
private:
    vector<vector<int>> dp;
    int n;
    
public:
    int f(vector<int>& stones, int s, int i) {
        if (i == n) {
            return s < 0 ? 1e9 : s;
        }
        if (dp[i][s + 3000] != -1) {
            return dp[i][s + 3000];
        }
        int t = min(f(stones, s + stones[i], i + 1), f(stones, s - stones[i], i + 1));
        return dp[i][s + 3000] = t;
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        dp.resize(n, vector<int>(6005, -1));
        return f(stones, 0, 0);
    }
};