const int maxn = 501;
int dp[maxn][maxn];

class Solution {
private:
    int n;
    vector<int> satisfaction;
    
public:
    int dfs(int index, int coefficient) {
        if (index >= n) {
            return 0;
        }
        if (dp[index][coefficient] != -1) {
            return dp[index][coefficient];
        }
        int choose[2];
        choose[0] = dfs(index + 1, coefficient);
        choose[1] = coefficient * satisfaction[index] + dfs(index + 1, coefficient + 1);
        return dp[index][coefficient] = max(choose[0], choose[1]);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof(dp));
        this->n = satisfaction.size();
        this->satisfaction = satisfaction;
        return dfs(0, 1);
    }
};