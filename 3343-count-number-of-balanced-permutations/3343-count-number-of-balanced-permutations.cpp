using ll = long long;

const ll MOD = 1e9 + 7;
ll memo[10][41][41][361];
ll memo_comb[41][41];

class Solution {
private:
    unordered_map<ll, ll> freq;
    ll target;
    
public:
    ll comb(ll n, ll k) {
        if (k > n) {
            return 0;
        }
        if (k < 0) {
            return 0;
        }
        if (n == 0) {
            return k == 0;
        }
        if (memo_comb[n][k] != -1) {
            return memo_comb[n][k];
        }
        return memo_comb[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % MOD;
    }
    
    ll dp(ll num, ll odd, ll even, ll half_sum) {
        if (odd == 0 && even == 0 && half_sum == 0) {
            return 1;
        }
        if (num < 0 || half_sum < 0 || odd < 0 || even < 0) {
            return 0;
        }
        if (memo[num][odd][even][half_sum] != -1) {
            return memo[num][odd][even][half_sum];
        }
        ll ans = 0;
        for (ll c = 0; c <= freq[num]; ++c) {
            ll val = (comb(odd, c)*comb(even, freq[num] - c)) % MOD;
            val = (val*dp(num - 1, odd - c, even - (freq[num] - c), half_sum - num*c)) % MOD;
            ans = (ans + val) % MOD;
        }
        return memo[num][odd][even][half_sum] = ans;
    }
    
    ll countBalancedPermutations(string num) {
        // dp(num, amount of even indices, amount of odd indices, total of 1 or 2)
        const ll n = num.size();
        
        for (ll i = 0; i < n; ++i) {
            freq[num[i] - '0']++;  
            this->target += num[i] - '0';
        }
        
        if (this->target & 1) {
            return 0;
        }
        
        this->target /= 2;
        
        memset(memo, -1, sizeof(memo));
        memset(memo_comb, -1, sizeof(memo_comb));
        
        return dp(9, n/2, n - n/2, this->target);
    }
};