int memo[501][1001];

class Solution {
private:
    vector<int> cost;
    vector<int> time;
    int n;
    
public:
    int dp(int i, int s) {
        if (i == n) {
            return s < 0 ? 1e9 : 0;
        }
        if (memo[i][s + 500] != -1) {
            return memo[i][s + 500];
        }
        return memo[i][s + 500] = min({
            cost[i] + dp(i + 1, min(n, s + time[i])),
            dp(i + 1, s - 1)  
        });
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(memo, -1, sizeof(memo));
        this->n = cost.size();
        this->cost = cost;
        this->time = time;
        return dp(0, 0);
    }
};