int memo[301][1001][11];

class Solution {
private:
    int size_jobdiff;
    vector<int> jobDifficulty;
    
public:
    int dp(int i, int p, int d) {
        if (i == size_jobdiff) {
            return d == 0 ? 0 : 1e8;
        }
        if (d <= 0) {
            return 1e8;
        }
        if (memo[i][p][d] != -1) {
            return memo[i][p][d];
        }
        return memo[i][p][d] = min({
            dp(i + 1, max(p, jobDifficulty[i]), d),
            max(p, jobDifficulty[i]) + dp(i + 1, 0, d - 1),
        });
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        size_jobdiff = jobDifficulty.size();
        if (size_jobdiff < d) {
            return -1;
        }
        this->jobDifficulty = jobDifficulty;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, d);
    }
};