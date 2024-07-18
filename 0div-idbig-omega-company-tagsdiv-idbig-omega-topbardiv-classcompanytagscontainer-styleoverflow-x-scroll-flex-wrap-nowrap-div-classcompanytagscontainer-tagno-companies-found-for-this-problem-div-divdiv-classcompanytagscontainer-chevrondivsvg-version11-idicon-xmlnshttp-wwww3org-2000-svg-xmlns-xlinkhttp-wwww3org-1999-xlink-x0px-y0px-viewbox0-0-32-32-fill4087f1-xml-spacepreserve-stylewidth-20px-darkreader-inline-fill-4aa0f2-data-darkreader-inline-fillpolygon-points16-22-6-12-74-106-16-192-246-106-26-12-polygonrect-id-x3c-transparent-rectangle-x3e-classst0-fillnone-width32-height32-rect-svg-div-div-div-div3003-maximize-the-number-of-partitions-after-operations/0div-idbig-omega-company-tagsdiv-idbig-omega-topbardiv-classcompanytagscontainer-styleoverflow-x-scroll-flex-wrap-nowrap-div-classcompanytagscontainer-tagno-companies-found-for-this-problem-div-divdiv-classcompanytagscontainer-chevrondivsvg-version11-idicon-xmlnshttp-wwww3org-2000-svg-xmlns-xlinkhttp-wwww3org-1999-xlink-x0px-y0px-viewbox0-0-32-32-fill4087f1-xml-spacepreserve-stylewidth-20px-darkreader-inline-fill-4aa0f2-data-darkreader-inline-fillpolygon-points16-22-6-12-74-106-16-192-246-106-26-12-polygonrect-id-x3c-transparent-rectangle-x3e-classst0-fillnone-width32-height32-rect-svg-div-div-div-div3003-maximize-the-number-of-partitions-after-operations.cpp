class Solution {
private:
    unordered_map<long long, long long> memo;
    string s;
    int k;
    
public:
    long long dp(long long i, long long option, long long mask) {
        long long key = (i << 27) | (mask << 1) | option;
        
        if (i == s.size()) {
            return 1;
        }
        
        if (memo.count(key)) {
            return memo[key];
        }
        
        long long ans = 0;
        long long new_mask = mask | (1 << (s[i] - 'a'));
        
        if (__builtin_popcountll(new_mask) > k) {
            ans = max(ans, 1 + dp(i + 1, option, (1 << (s[i] - 'a'))));
        } else {
            ans = max(ans, dp(i + 1, option, new_mask));
        }
                      
        if (option == 0) {
            for (int c = 0; c < 26; ++c) {
                long long new_mask = mask | (1 << c);
                if (__builtin_popcountll(new_mask) > k) {
                    ans = max(ans, 1 + dp(i + 1, !option, (1 << c)));
                } else {
                    ans = max(ans, dp(i + 1, !option, new_mask));
                }
            }
        }
        
        return memo[key] = ans;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        return dp(0, 0, 0);
    }
};
