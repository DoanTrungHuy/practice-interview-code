int memo[2][100001];

class Solution {
private:
    vector<int> prefSum;
    int n;
    
public:
    int dp(bool isAlice, int i) {
        if (i == n) {
            return isAlice ? prefSum[i] : -prefSum[i];
        }
        if (memo[isAlice][i] != -1) {
            return memo[isAlice][i];
        }
        if (isAlice) {
            return memo[isAlice][i] = max(
                prefSum[i] + dp(!isAlice, i + 1),
                dp(isAlice, i + 1)
            );
        }
        return memo[isAlice][i] = min(
            -prefSum[i] + dp(!isAlice, i + 1), 
            dp(isAlice, i + 1)
        );
    }
    int stoneGameVIII(vector<int>& stones) {
        this->n = stones.size();
        prefSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + stones[i];
        }
        memset(memo, -1, sizeof(memo));
        return dp(true, 2);
    }
};