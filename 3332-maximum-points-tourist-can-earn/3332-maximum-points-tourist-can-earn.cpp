int memo[300][300];

class Solution {
private:
    int n, k;
    vector<vector<int>> stayScore, travelScore;
    
public:
   int dp(int day, int c_city) {
        if (day == k) {
            return 0;
        }

        if (memo[day][c_city] != -1) {
            return memo[day][c_city];
        }

        int ans = stayScore[day][c_city] + dp(day + 1, c_city);

        for (int n_city = 0; n_city < n; ++n_city) {
            ans = max(ans, travelScore[c_city][n_city] + dp(day + 1, n_city));
        }

        return memo[day][c_city] = ans;
    };
    
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        memset(memo, -1, sizeof memo);
        this->n = n;
        this->k = k;
        this->stayScore = stayScore;
        this->travelScore = travelScore;
        int ans = 0;
        for (int s_city = 0; s_city < n; ++s_city) {
            ans = max(ans, dp(0, s_city));
        }
        return ans;
    }
};
