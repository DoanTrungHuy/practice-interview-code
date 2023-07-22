class Solution {
private:
    vector<int> map_mask, primes;
    unordered_map<int, int> cnt;
    
public:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }    
        for (int d = 2; d <= (int)sqrt(num); ++d) {
            if (num % d == 0) {
                return false;
            }
        }
        return true;
    }
    
    int MOD = 1e9 + 7;
    
    using ll = long long;
    
    ll memo[1 << 10][31];
    
    ll dp(int mask, int num) {
        if (num == 1) {
            return 1;
        }
        if (memo[mask][num] != -1) {
            return memo[mask][num];
        }
        ll res = dp(mask, num - 1);
        if (map_mask[num] > 0 and (mask | map_mask[num]) == mask) {
            res = (res + dp(mask ^ map_mask[num], num - 1)*cnt[num]) % MOD;
        }
        return memo[mask][num] = res;
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        
        for (int num : nums) {
            cnt[num]++;
        }
        
        map_mask.resize(31, 0);
        
        for (int num = 2; num <= 30; ++num) {
            if (isPrime(num)) {
                primes.push_back(num);
            }
        }
        
        for (int num = 2; num <= 30; ++num) {
            if (num % 4 == 0 or num % 9 == 0 or num % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < primes.size(); ++i) {
                if (num % primes[i] == 0) {
                    mask ^= (1 << i);
                }
            }
            map_mask[num] = mask;
        }
        
        ll res = dp((1 << 10) - 1, 30) - 1;
        
        while (cnt[1]--) {
            res = (res * 2) % MOD;
        }
        
        return (int)(res + MOD) % MOD;
    }
};