int memo[101][201];
const int MOD = 1e9 + 7;

class Solution {
private:
    vector<int> locations;
    int finish;
    int n;
    
public:
    int dp(int i, int fuel) {
        if (fuel < 0) {
            return 0;
        }
        if (memo[i][fuel] != -1) {
            return memo[i][fuel];
        }
        int ans = (i == finish);
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            ans = (ans + dp(j, fuel - abs(locations[i] - locations[j]))) % MOD;
        }
        return memo[i][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        this->locations = locations;
        this->finish = finish;
        this->n = locations.size();
        memset(memo, -1, sizeof(memo));
        return dp(start, fuel);
    }
};