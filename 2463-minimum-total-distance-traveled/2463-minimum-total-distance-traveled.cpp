using ll = long long;
ll memo[101][101][101];

class Solution {
private:
    vector<int> robot;
    vector<vector<int>> factory;
    int n, m;
    
public:
    ll dp(int i, int j, int limit) {
        if (i == n) {
            return 0;
        }
        if (memo[i][j][limit] != -1) {
            return memo[i][j][limit];
        }
        ll ans = 1e18;
        if (limit) {
            ans = min(ans, dp(i + 1, j, limit - 1) + abs(robot[i] - factory[j][0]));
        }
        if (j + 1 < m) {
            ans = min(ans, dp(i, j + 1, factory[j + 1][1]));
        }
        return memo[i][j][limit] = ans;
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(memo, -1, sizeof memo);
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        this->robot = robot;
        this->factory = factory;
        this->n = robot.size();
        this->m = factory.size();
        return dp(0, 0, factory[0][1]);
    }
};