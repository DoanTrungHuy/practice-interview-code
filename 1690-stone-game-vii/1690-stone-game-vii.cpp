int memo[2][1001][1001];

class Solution {
private:
    vector<int> prefSum;
    int n;
    
public:
    int getSum(int left, int right) {
        return prefSum[right + 1] - prefSum[left];    
    }
    
    int dp(bool isAlice, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (memo[isAlice][left][right] != -1) {
            return memo[isAlice][left][right];
        }
        if (isAlice) {
            return memo[isAlice][left][right] = max(
                dp(!isAlice, left, right - 1) + getSum(left, right - 1),
                dp(!isAlice, left + 1, right) + getSum(left + 1, right)
            );
        }
        else {
            return memo[isAlice][left][right] = min(
                dp(!isAlice, left, right - 1) - getSum(left, right - 1),
                dp(!isAlice, left + 1, right) - getSum(left + 1, right)
            );
        }
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(memo, -1, sizeof(memo));
        this->n = stones.size();
        prefSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + stones[i];
        }
        return dp(true, 0, n - 1);
    }
};