using ll = long long;
const ll MOD = 1e9 + 7;
const ll MN = 1e4 + 10;
const ll MM = 30;
int memo1[MN][MM];
int memo2[MM][MN];

class Solution {
private:
    vector<vector<ll>> num_div;
    int n;
    
public:
    ll dp(int i, int j) {
        if (j == 1) {
            return 1;
        }
        if (memo1[i][j] != -1) {
            return memo1[i][j];
        }
        ll ans = 0;
        for (ll x : num_div[i]) {
            ans = (ans + dp(x, j - 1)) % MOD;
        }
        return memo1[i][j] = ans;
    }
    
    ll C(int i, int j) {
        if (j == 0) {
            return i == 0;
        }
        if (i == 0) {
            return 0;
        }
        if (memo2[i][j] != -1) {
            return memo2[i][j];
        }
        return memo2[i][j] = (C(i, j - 1) + C(i - 1, j - 1)) % MOD;
    }
    
    int idealArrays(int n, int maxValue) {
        this->n = n;
        num_div.resize(maxValue + 1);
        
        for (int val = 1; val <= maxValue; ++val) {
            for (int multiple = 2*val; multiple <= maxValue; multiple += val) {
                num_div[val].push_back(multiple);
            }
        }
        
        memset(memo1, -1, sizeof(memo1));
        memset(memo2, -1, sizeof(memo2));
        
        ll ans = 0;
        
        for (int k = 1; k < MM; ++k) {
            for (int j = 1; j <= maxValue; ++j) {
                ans = (ans + C(k, n)*dp(j, k)) % MOD;
            }
        }
        
        return ans;
    }
};