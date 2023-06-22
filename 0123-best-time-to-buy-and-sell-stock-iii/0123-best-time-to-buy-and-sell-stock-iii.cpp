const int MAXN = 1e5;
int memo[MAXN][2][3];

class Solution {
private:
    vector<int> prices;
    int n;
        
public:
    int dp(int i, int state, int cnt) {
        if (i == n) {
            return 0;
        }
        if (memo[i][state][cnt] != -1) {
            return memo[i][state][cnt];
        }
        if (cnt == 2) {
            return memo[i][state][cnt] = dp(i + 1, state, cnt);
        }
        if (state == 0) {
            return memo[i][state][cnt] = max(
                -prices[i] + dp(i + 1, !state, cnt), 
                dp(i + 1, state, cnt)
            );
        }
        else {
            return memo[i][state][cnt] = max(
                prices[i] + dp(i + 1, !state, cnt + 1), 
                dp(i + 1, state, cnt)
            );
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        this->prices = prices;
        this-> n = prices.size();
        return dp(0, 0, 0);
    }
};