class Solution {
private:
    vector<int> arr;

public:
    int memo[100002][2][2];
    int MOD = 1e9 + 7;

    int dp(int i, bool t, bool o) {
        if (i == arr.size()) {
            return o;
        }
        if (memo[i][t][o] != -1) {
            return memo[i][t][o];
        }
        int including = dp(i + 1, 1, o ^ (arr[i] % 2));
        int excluding = 0;
        if (t) {
            excluding = dp(arr.size(), 1, o);
        }
        else {
            excluding = dp(i + 1, 0, 0);
        }
        return memo[i][t][o] = (including + excluding) % MOD;
    }

    int numOfSubarrays(vector<int>& arr) {
        this->arr = arr;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0);
    }
};