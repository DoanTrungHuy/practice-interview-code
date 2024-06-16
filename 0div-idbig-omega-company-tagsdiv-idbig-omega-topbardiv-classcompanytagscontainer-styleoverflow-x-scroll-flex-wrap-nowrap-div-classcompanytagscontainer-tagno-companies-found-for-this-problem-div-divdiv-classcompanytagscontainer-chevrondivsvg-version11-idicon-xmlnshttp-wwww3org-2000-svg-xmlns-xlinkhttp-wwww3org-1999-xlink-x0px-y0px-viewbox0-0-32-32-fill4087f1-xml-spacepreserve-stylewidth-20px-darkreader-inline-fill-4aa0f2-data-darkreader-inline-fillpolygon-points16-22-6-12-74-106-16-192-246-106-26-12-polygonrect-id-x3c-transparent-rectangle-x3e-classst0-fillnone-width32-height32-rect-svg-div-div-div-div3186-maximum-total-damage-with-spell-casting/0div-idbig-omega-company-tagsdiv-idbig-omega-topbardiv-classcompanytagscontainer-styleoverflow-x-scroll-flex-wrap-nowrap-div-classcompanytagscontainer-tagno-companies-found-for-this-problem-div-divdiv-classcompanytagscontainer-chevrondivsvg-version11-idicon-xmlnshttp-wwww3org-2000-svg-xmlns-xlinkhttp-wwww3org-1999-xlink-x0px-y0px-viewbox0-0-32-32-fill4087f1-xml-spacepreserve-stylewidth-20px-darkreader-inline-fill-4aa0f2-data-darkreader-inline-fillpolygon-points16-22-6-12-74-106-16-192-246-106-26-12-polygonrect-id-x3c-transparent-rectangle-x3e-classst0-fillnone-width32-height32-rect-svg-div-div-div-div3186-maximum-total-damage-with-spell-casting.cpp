const int MAXN = 1e5 + 10;
long long memo[MAXN];

class Solution {
private:
    vector<int> power;
    map<int, int> um;        // map to count occurrences of each spell damage
    multiset<int> ms;        // multiset to maintain sorted spell damages
    
public:
    long long dp(int i) {
        if (i >= power.size()) {
            return 0;
        }        
        if (memo[i] != -1) {
            return memo[i];
        }
        int idx = power.size();
        long long left = 0;
        long long right = power.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (power[mid] > power[i] + 2) {
                idx = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return memo[i] = max(dp(i + 1), dp(idx) + (long long)power[i] * um[power[i]]);
    }
    
    long long maximumTotalDamage(vector<int>& power) {
        const int n = power.size();
        sort(power.begin(), power.end());         // sort spell damages
        
        this->power = power;
        memset(memo, -1, sizeof(memo));           // initialize memoization array

        // populate um and ms with spell damages
        for (int i = 0; i < n; ++i) {
            um[power[i]]++;
            ms.insert(power[i]);
        }
        
        return dp(0);   // start dynamic programming recursion
    }
};
