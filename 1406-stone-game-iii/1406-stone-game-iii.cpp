class Solution {
private:
    vector<int> stoneValue;
    int n;

public:
    const int k = 3;
    int memo[2][(int)5e4 + 1];

    int dp(bool Alice, int i) {
        if (i == n) {
            return 0;
        }
        if (memo[Alice][i] != -1) {
            return memo[Alice][i];
        }
        int ans = Alice ? INT_MIN : INT_MAX;
        int total = 0;
        for (int j = i; j < min(i + 3, n); ++j) {
            total += stoneValue[j];
            if (Alice) {
                ans = max(ans, total + dp(!Alice, j + 1));
            }
            else {
                ans = min(ans, dp(!Alice, j + 1));
            }
        }
        return memo[Alice][i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        this->n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        int Alice = dp(true, 0);
        int total = 0;
        for (int value : stoneValue) {
            total += value;
        }
        int Bob = total - Alice;
        if (Alice > Bob) {
            return "Alice";
        }
        else if (Alice < Bob) {
            return "Bob";
        }
        return "Tie";
    }
};