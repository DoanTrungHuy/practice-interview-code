const int MAXN = 1e5;
int sieve[MAXN + 1];

class Solution {
private:
    unordered_map<int, vector<int>> factors_set;
    vector<int> parent;
    
public:
    vector<int> factors_primes(int num) {
        vector<int> primes;
        while (num != 1) {
            int k = sieve[num];
            while (num % k == 0) {
                num /= k;
            }
            primes.push_back(k);
        }
        return primes;
    }
    
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 2; i <= MAXN; ++i) {
            if (sieve[i]) {
                continue;
            }
            sieve[i] = i;
            for (int j = 2*i; j <= MAXN; j += i) {
                if (sieve[j]) {
                    continue;
                }
                sieve[j] = i;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            vector<int> primes = factors_primes(nums[i]);
            for (int prime : primes) {
                factors_set[prime].push_back(i);
            }
        }
        
        parent.resize(n);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (auto [_, factors] : factors_set) {
            for (int i = 1; i < factors.size(); ++i) {
                int u = find(factors[0]);
                int v = find(factors[i]);
                if (u != v) {
                    parent[u] = v;
                }
            }
        }
        
        int p0 = find(0);
        
        for (int i = 1; i < n; ++i) {
            if (find(i) != p0) {
                return false;
            }
        }
        
        return true;
    }
};