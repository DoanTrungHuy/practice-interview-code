class Solution {
private:
    long long ans;
    int n;
    vector<vector<int>> questions;
    vector<long long> memo;
    
public:
    long long dp(int i) {
        if (i >= n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        return memo[i] = max(dp(i + questions[i][1] + 1) + questions[i][0], dp(i + 1));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size(), ans = 0;
        this->questions = questions;
        memo.resize(n, -1);
        return dp(0);
    }
};