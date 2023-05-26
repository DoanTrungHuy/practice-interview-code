int memo[501];

class Solution {
private:
    vector<int> piles;
    int n;
    
public:
    int dp(int i) {
        if (i == n / 2) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int left = piles[i] + dp(i + 1);
        int right = piles[n - i - 1] + dp(i + 1);
        return memo[i] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        memset(memo, -1, sizeof(memo));
        this->piles = piles;
        this->n = piles.size();
        int alice = dp(0);
        return alice > accumulate(piles.begin(), piles.end(), 0) - alice;
    }
};