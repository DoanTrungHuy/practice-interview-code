const int MAXN = 500;
int memo[MAXN + 1][MAXN + 1];

class Solution {
private:
    vector<int> stoneValue;
    int n;
    vector<int> prefSum;

public:
    int dp(int left, int right) {
        if (left == right) {
            return 0;
        }
        
        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int ans = 0;

        for (int mid = left + 1; mid <= right; ++mid) {
            int leftStone = prefSum[mid] - prefSum[left];
            int rightStone = prefSum[right + 1] - prefSum[mid];

            if (leftStone < rightStone) {
                ans = max(ans, leftStone + dp(left, mid - 1));
            }
            else if (rightStone < leftStone) {
                ans = max(ans, rightStone + dp(mid, right));
            }
            else {
                ans = max(
                    ans, 
                    leftStone + max(dp(left, mid - 1), dp(mid, right))
                );
            }
        }

        return memo[left][right] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        this->n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        prefSum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + stoneValue[i];
        }
        return dp(0, n - 1);
    }
};