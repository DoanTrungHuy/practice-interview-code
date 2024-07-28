using ll = long long;

const ll MN = 2e2 + 10;
ll memo[MN][MN];

class Solution {
private:
    map<pair<int, int>, long long> mp;
    int n, m;
    
public:
    // dp(3, 5) -> dp(1, 5) + dp(2, 5)
    // dp(3, 5) -> dp(3, 1) + dp(3, 4)
    
    ll dp(int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        ll ans = mp[{i, j}];
        for (int k = 1; k < j; ++k) {
            ans = max(ans, dp(i, k) + dp(i, j - k));
        }
        for (int k = 1; k < i; ++k) {
            ans = max(ans, dp(k, j) + dp(i - k, j));
        }
        return memo[i][j] = ans;
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        this->n = n;
        this->m = m;
        memset(memo, -1, sizeof(memo));
        
        for (vector<int> p : prices) {
            int h = p[0];
            int w = p[1];
            int c = p[2];
            mp[{h, w}] = c;
        }
        
        return dp(m, n);
    }
};